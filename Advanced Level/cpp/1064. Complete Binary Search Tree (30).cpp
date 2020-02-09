#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//���������Ľڵ���
//x:�����ĸ��ڵ�, n:��ȫ�����ܽڵ���
int SubTreeSize(int x, int n)
{
	if( x > n)
		return 0;
	return 1 + SubTreeSize(x*2,n) + SubTreeSize(x*2+1,n);
};

//ȷ��x�ڵ��key�����������ǵڼ�С
int node_order[1001];
void NodeOrder(int x,int order_offset,int n)//���ڵ��order_offset = 0
{
	if(x>n)
		return ;
	node_order[x] = order_offset + 1 + SubTreeSize(2*x,n);
	NodeOrder(x*2,order_offset,n);//left node
	NodeOrder(x*2+1,node_order[x],n);//right node
};


int main()
{
	int x[1001];
	int n,k;
	cin >> n;
	vector<int> a(n+1);
	for(k = 1; k <= n; ++k)
		scanf("%d",&a[k]);
	
	sort(a.begin(),a.end());
	NodeOrder(1,0,n);
	for(k = 1; k <= n; ++k)
		x[k] = a[ node_order[k] ];

	//print
	for(k = 1; k <= n; ++k)
	{
		if(k > 1)
			printf(" ");
		printf("%d",x[k]);
	}
	cout << endl;

	return 0;
}