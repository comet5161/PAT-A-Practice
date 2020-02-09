//输入时用"%ld",如果用"%d"的话会有2个测试点通不过?
//数组容量超过1000*1000时要声明成全局变量或int* x = new int[1000*1000],不能声明成局部变量
//

#include<iostream>
#include<vector>

#define MAX_SIZE 1000001

using namespace std;

long a[MAX_SIZE],b[MAX_SIZE],c[MAX_SIZE];

//增序数组a的最大值<=数组b的最小值
long MedianOfSort(long *a,long ea,long *b,long eb)
{
	long mid;
	mid = (ea+eb+1)/2;
	if(mid <= ea)
		return a[mid];
	return b[mid-ea-1];
}

//a,b都是增序数组
long Median(long* a,long ea,long* b,long eb)
{
	long ma;
	long mb;
	ma = (ea)/2;
	mb = (eb)/2;

	if( a[0] >= b[eb])
		return MedianOfSort(b,eb,a,ea);
	if( b[0] >= a[ea])
		return MedianOfSort(a,ea,b,eb);
	if(ea == 0 )
		if(eb == 1)
			return a[0];
		else
			Median(a,0,b+eb/2,eb-(eb/2)*2);
	if(eb == 0)
		if(ea == 1)
			return b[0];
		else
			Median(a+(ea/2),ea-(ea/2)*2,b,0);
	if(ea == 1 && eb == 1)
		if(a[0] > b[0])
			return a[0];
		else
			return b[0];
	long mid = ma<mb?ma:mb;
	if(mid == 0)
		mid = 1;
	if(a[ma] <= b[mb])
		return Median(a+mid,ea-mid,b,eb-mid);
	else
		return Median(a,ea-mid,b+mid,eb-mid);
}

int main()
{
	long ia,ib,ic;
	long m,n;
	cin >> m;
	for(long k = 0; k < m; ++k)
		scanf("%ld",&a[k]);
	cin >> n;
	for(long k = 0; k < n; ++k)
		scanf("%ld",&b[k]);

	//way1 先合并，再求中位数
	//ia = ib = 0;
	//ic = -1;
	//while(ia < m && ib < n)
	//{
	//	if(a[ia] < b[ib])
	//		c[++ic] = a[ia++];
	//	else
	//		c[++ic] = b[ib++];
	//}
	//while( ia < m)
	//	c[++ic] = a[ia++];
	//while( ib < n)
	//	c[++ic] = b[ib++];
	//printf("%d\n",c[ic/2]);

	//分治法
	long mid = Median(a,m-1,b,n-1);
	cout << mid;

	return 0;
}