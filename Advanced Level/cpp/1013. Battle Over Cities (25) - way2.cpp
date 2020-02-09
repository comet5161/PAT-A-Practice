//使用不相交集(并查集)算法
//因为输入数据量大，不要用cin，scanf快些


#include<iostream>
using namespace std;

int root[1001];
int path[1000*1000][2];

int findRoot(int c)
{
	if(c == root[c])
		return c;
	return findRoot( root[c] );
};

void Union(int a, int b)
{
	int r = findRoot(a); 
	int r2 = findRoot(b);
	root[r2] = r;
}

int main()
{
	int N,M,K;
	cin >> N >> M >> K;
	for(int k = 0; k < M; ++k)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		path[k][0] = a;
		path[k][1] = b;
	}

	int cut,count = 0;
	for(int k = 0; k < K; ++k)
	{
		for(int j = 1; j <= N; ++j)
			root[j] = j;
		cin >> cut;
		for(int j = 0; j < M; ++j)
			if(path[j][0] != cut && path[j][1] != cut)
				Union(path[j][0],path[j][1]);
		count = 0;
		for(int j = 1; j <= N; ++j)
			if(root[j] == j)
				++count;
		cout << (count - 2) << endl;
	}
	return 0;
}