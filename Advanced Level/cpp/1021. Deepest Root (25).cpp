//本题的输入图是默认没有环的

//测式用例:
/*
6
1 4
2 3
3 4
4 5
5 6
正确结果：
2
6
错误：
1
2
6

*/

#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string.h>
#define MAX_SIZE 10001
#define INF 999999999
using namespace std;

int FindRoot(int root[],int x)
{
	if(root[x] == x)
		return x;
	return FindRoot(root, root[x]);
}

void Union(int root[], int a, int b)
{
	int r1 = FindRoot(root,a);
	int r2 = FindRoot(root,b);
	root[r2] = r1;
}

vector<int> Nodes[MAX_SIZE];
bool known[MAX_SIZE];
int max_depth = 0;
set<int> list;

//way1
//DFS
int Deepest(int src,int x,int depth)
{
	++depth;
	known[x] = true;
	for(auto i = Nodes[x].begin(); i != Nodes[x].end(); ++i)
		if(known[ *i ] == false  )
			Deepest(src,*i,depth);

	//测试点1是总共只有1个结点的情况，如果写idx[x] == 0，会通不过
	//if( idx[x] <= 0 && depth >= max_depth)//如果该结点为叶子结点并且
	if(depth >= max_depth)
	{
		//将x和src结点加入到list中
		if(depth > max_depth)
			list.clear();
		list.insert(src);
		list.insert(x);
		max_depth = depth;
	}
	return depth;
}

//way2
//BFS
int que[MAX_SIZE];
int BFS(int x)
{
	int fore,rear,end;
	int depth = 0;
	vector<int> endList;
	fore = rear = -1;
	que[++fore] = x;
	known[x] = true;
	end = 0;
	while(++rear <= fore)
	{
		int cur = que[rear];
		for(auto i = Nodes[cur].begin(); i != Nodes[cur].end(); ++i)
			if(known[*i] == false)
			{
				known[*i] = true;
				que[++fore] = *i;
			}
		if(rear == end)
		{
			endList.push_back(end);
			++depth;
			end = fore;
		}
	}
	if(depth >= max_depth)
	{
		//将x和以x为根的树的最底层的所有结点加入到list中，测试点3用时48ms，如果只加x结点，用时1480ms
		if(depth > max_depth)
			list.clear();
		list.insert(x);
		int size = endList.size();
		if(size > 1)
			for(int k = endList[size-2]+1; k <= endList[size-1]; ++k)
				list.insert(que[k]);
		max_depth = depth;
	}
	return depth;
}

int main()
{
	int n,k;
	int edge[MAX_SIZE][2];
	int root[MAX_SIZE];
	cin >> n;

	for(k = 1; k <= n; ++k)
		root[k] = k;

	for(k = 0; k < n-1; ++k)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		edge[k][0] = a;
		edge[k][1] = b;
		Nodes[a].push_back(b);
		Nodes[b].push_back(a);
	}

	//查看图是否连通
	for(k = 0; k < n-1; ++k)
		Union(root, edge[k][0],edge[k][1]);
	int count = 0;
	for(k = 1; k <= n; ++k)
		if(root[k] == k)
			++count;
	if(count != 1 )
	{
		cout << "Error: " << count << " components";
		return 0;
	}
	//查找最深根结点
	for(k = 1; k <= n; ++k)
	{
		//if(n > 1000) break;
		if(Nodes[k].size() > 1)//如果一个节点连接另外2个或更多节点，则该点一定非depest root
			continue;
		if(list.find(k) != list.end())
			continue;
		memset(known,false,sizeof(known));  
		//way1 DFS 测试点3可能超时
		//Deepest(k,k,0);
		//Way2 BFS
		BFS(k);
		
	}
	//再次检查，防止有漏网之鱼，如前面测试用例的情况
	memset(known,false,sizeof(known));  
	BFS(*list.rbegin());

	for(auto i = list.begin(); i != list.end(); ++i)
		cout << *i << endl;

	return 0;
}