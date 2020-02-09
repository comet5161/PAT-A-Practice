//���������ͼ��Ĭ��û�л���

//��ʽ����:
/*
6
1 4
2 3
3 4
4 5
5 6
��ȷ�����
2
6
����
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

	//���Ե�1���ܹ�ֻ��1��������������дidx[x] == 0����ͨ����
	//if( idx[x] <= 0 && depth >= max_depth)//����ý��ΪҶ�ӽ�㲢��
	if(depth >= max_depth)
	{
		//��x��src�����뵽list��
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
		//��x����xΪ����������ײ�����н����뵽list�У����Ե�3��ʱ48ms�����ֻ��x��㣬��ʱ1480ms
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

	//�鿴ͼ�Ƿ���ͨ
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
	//������������
	for(k = 1; k <= n; ++k)
	{
		//if(n > 1000) break;
		if(Nodes[k].size() > 1)//���һ���ڵ���������2�������ڵ㣬��õ�һ����depest root
			continue;
		if(list.find(k) != list.end())
			continue;
		memset(known,false,sizeof(known));  
		//way1 DFS ���Ե�3���ܳ�ʱ
		//Deepest(k,k,0);
		//Way2 BFS
		BFS(k);
		
	}
	//�ٴμ�飬��ֹ��©��֮�㣬��ǰ��������������
	memset(known,false,sizeof(known));  
	BFS(*list.rbegin());

	for(auto i = list.begin(); i != list.end(); ++i)
		cout << *i << endl;

	return 0;
}