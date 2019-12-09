#include<iostream>
#include<time.h>
#include<string>
#include<algorithm>
using namespace std;
const int MAXSIZE = 2000;//数组的最大长度
const int OFFSET = 3000;//桶的边界条件
const int KIND = 12;//排序的种类
#define  M 1000//排序函数的执行次数
int a[MAXSIZE];//排序数组
string str[KIND] = { "冒泡排序", "改进冒泡排序", "直接插入排序", "折半插入排序", "简单选择排序","希尔排序", "快速排序算法","堆排序" ,"桶排序","计数排序","基数排序","二路归并排序"};//算法名称
struct statistic
{
	string name;
	double run_time;
	statistic() { run_time = 0; }
}Data[KIND];//数据统计结构体
bool cmp(statistic a, statistic b)
{
	return (a.run_time < b.run_time);
}
//初始化数据表
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
	cout << "***************排序数据显示***********" << endl;
	for (int i = 1; i <= KIND; i++)
	{
		cout << i << " :" << data[i-1].name << "  time ->" << data[i-1].run_time<<"ms"<< endl;
	}
}
//初始化数组
bool inital(int *ans,int n)
{
	if (n >= MAXSIZE)return false;
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		ans[i] = rand()%MAXSIZE+1;
	}
}
//菜单
void Menu()
{
	cout << "******************排序方式实现***************************\n";
	cout << "*****************1，冒泡排序******************\n";
	cout << "*****************2，改进冒泡排序******************\n";
	cout << "*****************3，直接插入排序******************\n";
	cout << "*****************4，折半插入排序******************\n";
	cout << "*****************5，简单选择排序******************\n";
	cout << "*****************6，希尔排序******************\n";
	cout << "*****************7，快速排序算法****************\n";
	cout << "*****************8，堆排序****************\n";
	cout << "*****************9，桶排序****************\n";
	cout << "*****************10，计数排序****************\n";
	cout << "*****************11，基数排序****************\n";
	cout << "*****************12，二路归并排序****************\n";
	cout << "*****************13，排序算法数据统计****************\n";
	cout << "*******************0，退出********************\n";
	cout << "**********************************************\n";
	cout << "请选择一种排序的算法： " << endl;
}
//打印
void print_result(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//交换函数
void swap(int &a, int &b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
//一般冒泡排序
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
//改进的冒泡排序
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
//简单选择
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
//直接插入排序
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
//折半插入排序
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
/*希尔排序*/
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
/*快速排序*/
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
/*堆排序*/
void adjust(int *a ,int len,int index)/*调整函数 len是数组长度 index是第一个非叶子节点*/
{
	int left = 2 * index + 1;
	int right = 2 * index + 1;
	int maxid = index;
	if (left<len && a[left]>a[index])maxid = left;
	if (right<len && a[right]>a[index])maxid = right;
	if (maxid != index)
	{
		swap(a[maxid], a[index]);
		adjust(a, len, maxid);//递归调整堆
	}
}
void heapsort(int *a ,int size)
{
	//构建大根堆
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(a, size, i);
	}
	//调整大根堆
	for (int i = size - 1; i >= 1; i--)
	{
		swap(a[0], a[i]);
		adjust(a, i, 0);
	}
}
/*桶排序*/
void bucketSort(int *a ,int n)
{
	int tong[OFFSET];
	int ans = 0;
	//对桶里面的数组值置0
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
/*计数排序*/
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
/*基数排序*/
int getmaxbit(int *a,int n)//返回最大的位数
{
	int bit = 1;//最大位数
	int num = 10;//位数对应的最大值
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
/*二路归并*/
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
	
	cout << "输入所开辟的数组的大小:" << endl;
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