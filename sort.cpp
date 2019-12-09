#include<iostream>
#include<time.h>
#include<string>
#include<algorithm>
using namespace std;
const int MAXSIZE = 2000;//�������󳤶�
const int OFFSET = 3000;//Ͱ�ı߽�����
const int KIND = 12;//���������
#define  M 1000//��������ִ�д���
int a[MAXSIZE];//��������
string str[KIND] = { "ð������", "�Ľ�ð������", "ֱ�Ӳ�������", "�۰��������", "��ѡ������","ϣ������", "���������㷨","������" ,"Ͱ����","��������","��������","��·�鲢����"};//�㷨����
struct statistic
{
	string name;
	double run_time;
	statistic() { run_time = 0; }
}Data[KIND];//����ͳ�ƽṹ��
bool cmp(statistic a, statistic b)
{
	return (a.run_time < b.run_time);
}
//��ʼ�����ݱ�
void inital_data(statistic *data)
{
	for (int i = 0; i < KIND; i++)
	{
		data[i].name = str[i];
	}
}
void show_data(statistic *data)
{
	sort(data, data + KIND, cmp);
	cout << "***************����������ʾ***********" << endl;
	for (int i = 1; i <= KIND; i++)
	{
		cout << i << " :" << data[i-1].name << "  time ->" << data[i-1].run_time<<"ms"<< endl;
	}
}
//��ʼ������
bool inital(int *ans,int n)
{
	if (n >= MAXSIZE)return false;
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		ans[i] = rand()%MAXSIZE+1;
	}
}
//�˵�
void Menu()
{
	cout << "******************����ʽʵ��***************************\n";
	cout << "*****************1��ð������******************\n";
	cout << "*****************2���Ľ�ð������******************\n";
	cout << "*****************3��ֱ�Ӳ�������******************\n";
	cout << "*****************4���۰��������******************\n";
	cout << "*****************5����ѡ������******************\n";
	cout << "*****************6��ϣ������******************\n";
	cout << "*****************7�����������㷨****************\n";
	cout << "*****************8��������****************\n";
	cout << "*****************9��Ͱ����****************\n";
	cout << "*****************10����������****************\n";
	cout << "*****************11����������****************\n";
	cout << "*****************12����·�鲢����****************\n";
	cout << "*****************13�������㷨����ͳ��****************\n";
	cout << "*******************0���˳�********************\n";
	cout << "**********************************************\n";
	cout << "��ѡ��һ��������㷨�� " << endl;
}
//��ӡ
void print_result(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//��������
void swap(int &a, int &b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
//һ��ð������
void bubble_sort(int *a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j =n-1; j >i ; j--)
		{
			if (a[j-1] > a[j])
				swap(a[j-1], a[j]);
		}
	}
}
//�Ľ���ð������
void plus_bubble(int *a ,int n)
{
	bool exchange = false;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j >i; j--)
		{
			if (a[j - 1] > a[j])
			{
				exchange = true;
				swap(a[j - 1], a[j]);
			}
				
		}
		if (exchange == false)
			return;
	}
}
//��ѡ��
void simple_sort(int *a, int n) {

	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		if (k != i)
			swap(a[i], a[k]);
	}
}
//ֱ�Ӳ�������
void insertsort(int *a ,int n)
{
	int tmp,j;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			tmp = a[i];
			j = i - 1;
			while (j >= 0 && a[j] > tmp)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = tmp;
		}
	}
}
//�۰��������
void insert_midsort(int *a, int n)
{
	int low, high, mid;
	int tmp;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			tmp = a[i];
			low = 0; high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (tmp > a[mid])
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			for (int j = i - 1; j >= high+1 ; j--)
			{
				a[j + 1] = a[j];
			}
			a[high+1] = tmp;

		}

	}
}
/*ϣ������*/
void shellsort(int *a, int n)
{
	int i, j, d;
	int tmp;
	d = n / 2;
	while (d > 0)
	{
		for (int i = d; i < n; i++)
		{
			tmp = a[i];
			j = i - d;
			while (j >= 0 && a[j] > tmp)
			{
				a[j + d] = a[j];
				j = j - d;
			}
			a[j + d] = tmp;
		}
		d = d/2;

	}
}
/*��������*/
int quick_pos(int *a,int low,int high)
{
	int i = low; int j = high - 1;
	int tmp = a[i];
	while (i < j)
	{
		while (j > i && a[j] >= tmp)
			j--;
		while (j > i && a[i] <= tmp)
			i++;
		swap(a[i], a[j]);
	}

	swap(a[i],a[low]);
	return i;
}
void quick_sort(int *a, int low, int high)
{
	if (low < high) {
		int i = quick_pos(a, low, high);
		quick_sort(a, low, i);
		quick_sort(a, i + 1, high);
	}
}
/*������*/
void adjust(int *a ,int len,int index)/*�������� len�����鳤�� index�ǵ�һ����Ҷ�ӽڵ�*/
{
	int left = 2 * index + 1;
	int right = 2 * index + 1;
	int maxid = index;
	if (left<len && a[left]>a[index])maxid = left;
	if (right<len && a[right]>a[index])maxid = right;
	if (maxid != index)
	{
		swap(a[maxid], a[index]);
		adjust(a, len, maxid);//�ݹ������
	}
}
void heapsort(int *a ,int size)
{
	//���������
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(a, size, i);
	}
	//���������
	for (int i = size - 1; i >= 1; i--)
	{
		swap(a[0], a[i]);
		adjust(a, i, 0);
	}
}
/*Ͱ����*/
void bucketSort(int *a ,int n)
{
	int tong[OFFSET];
	int ans = 0;
	//��Ͱ���������ֵ��0
	for (int i = 0; i < OFFSET; i++)
	{
		tong[i] = 0;
	}
	for (int j = 0; j < n; j++)
	{
		tong[a[j]]++;
	}
	for (int k=0; k < OFFSET; k++)
	{
		while (tong[k])
		{
			a[ans++] = k;
			tong[k]--;
		}
	}

}
/*��������*/
void  countSort(int *a ,int n)
{
	int count[OFFSET] = { 0 };
	int *new_array = new int[n];
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
	}



	for (int j = 1; j < OFFSET; j++)
	{
		count[j] += count[j - 1];
	}

	for (int k = n - 1; k >= 0; k--)
	{
		int tmp = count[a[k]] - 1;
		new_array[tmp] = a[k];
		count[a[k]]--;
	}
	a = new_array;
}
/*��������*/
int getmaxbit(int *a,int n)//��������λ��
{
	int bit = 1;//���λ��
	int num = 10;//λ����Ӧ�����ֵ
	for (int i = 0; i < n; i++)
	{
		if (a[i] > num)
		{
			bit++;
			num *= 10;
		}
	}
	return bit;
}
void RadixSort(int *a, int n)
{
	int bit = getmaxbit(a, n);
	int radix = 1;
	int *bucket = new int[10];
	int *t = new int[n];
	for (int i = 0; i < bit; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			bucket[j] = 0;
		}
		int mod =10;
		for (int k = 0; k < n; k++)
		{
			bucket[(a[k]/radix) % mod]++;
		}

		for (int t = 1; t < 10; t++)
		{
			bucket[t] += bucket[t - 1];
		}

		for (int m = n - 1; m >= 0; m--)
		{
			int tmp = bucket[(a[m]/radix)%mod] - 1;
			t[tmp] = a[m];
			bucket[(a[m]/radix)%mod]--;
		}

		for (int s = 0; s < n; s++)
		{
			a[s] = t[s];
		}

		radix *= 10;
	}
}
/*��·�鲢*/
void merge(int *a, int *result, int i, int m, int n)
{
	int j = m + 1;
	int k = i;
	while (i<=m &&j<=n)
	{
		if (a[i] <= a[j])
		{
			result[k] = a[i++];
		}
		else
		{
			result[k] = a[j++];
		}
		k++;
	}
	while (i <= m)
	{
		result[k++] = a[i++];
	}
	while (j <= n)
	{
		result[k++] = a[j++];
	}
}
void MergeSort(int *source, int *result, int s, int t)
{
	if (s == t)source[s] = result[s];
	else
	{
		int tmp[MAXSIZE];
		int m = (s + t) / 2;
		MergeSort(source, tmp, s, m);
		MergeSort(source, tmp, m + 1, t);
		merge(tmp, result, s, m, t);
	}
}

int main()
{
	int n;
	int choice;
	
	cout << "���������ٵ�����Ĵ�С:" << endl;
	cin >> n;
	Menu();

	inital_data(Data);
	do {
		double start, end;
		cin >> choice;
		if (choice == KIND+1)
		{
			show_data(Data);
			continue;
		}
		start = (double)clock();
		for (int i = 0; i < M; i++)
		{
			inital(a, n);
			switch (choice)
			{
			case 1:bubble_sort(a, n); break;
			case 2:plus_bubble(a, n); break;
			case 3:insertsort(a, n); break;
			case 4:insert_midsort(a, n); break;
			case 5:simple_sort(a, n); break;
			case 6:shellsort(a, n); break;
			case 7:quick_sort(a, 0, n); break;
			case 8:heapsort(a, n); break;
			case 9:bucketSort(a, n); break;
			case 10:countSort(a, n); break;
			case 11:RadixSort(a,n); break;
			case 12:MergeSort(a, a, 0, n - 1); break;
			case 0:break;
			default:
				break;
			}
		}
		end = (double)clock();
		Data[choice - 1].run_time = end - start;
		printf("%s:%.6fms\n", Data[choice - 1].name.c_str(), (end - start));
	} while (choice != 0);
	
	system("pause");
	return 0;
}