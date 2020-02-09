#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

int data[100001];
int Next[100001];

int main()
{
	list<int> link;
	int head,n,m;
	int d,addr,ne;
	cin >> head >> n >> m;
	vector<int> v,vAddr;
	for(int k = 0; k < n;++k)
	{
		scanf("%d %d %d",&addr,&d,&ne);
		data[addr] = d;
		Next[addr] = ne;
	}

	int x = head;
	while(x != -1)
	{
		v.push_back(data[x]);
		vAddr.push_back(x);
		x = Next[x];
	}

	n = v.size();//可能有的节点不在link上

	int i = 0;
	int j = m - 1;
	while(i < n)
	{
		if(j<n)
		{
			reverse(v.begin()+i,v.begin()+j+1);
			reverse(vAddr.begin()+i,vAddr.begin()+j+1);
		}
		else 
			break;
		i += m;
		j += m;
	}
	for(int k = 0; k < n;++k)
	{
		printf("%05d %d ",vAddr[k],v[k]);
		if(k < n-1)
			printf("%05d\n",vAddr[k+1]);
		else printf("-1\n");
	}


	return 0;
}