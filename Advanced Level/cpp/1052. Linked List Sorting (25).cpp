/*
注意链表为空的情况和可能有的节点不在链表上
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Node{
public:
	int addr,key;
	Node(){}
	Node(int addr,int key):addr(addr),key(key){}
	friend bool operator < (const Node &a, const Node &b)
	{
		return a.key < b.key;
	}
};

int nextList[100000+1];
int keyList[100000+1];

int main()
{
	int head,addr,key,next,n;
	vector<Node> vect;
	cin >> n >> head;


	if( head == -1)
	{
		printf("0 -1\n");
		return 0;
	}


	for(int k = 0; k < n; ++k)
	{
		scanf("%d %d %d",&addr,&key,&next);
		nextList[addr] = next;
		keyList[addr] = key;
	}
	while(head != -1)
	{
		Node node(head,keyList[head]);
		vect.push_back(node);
		head = nextList[head];
	}

	sort(vect.begin(),vect.end());


	auto i = vect.begin();

	printf("%d %05d\n",vect.size(),i->addr);

	if(vect.size() == 1)
	{
		printf("%05d %d -1\n",i->addr,i->key);
		return 0;
	}

	for(; i != vect.end()-1; ++i)
		printf("%05d %d %05d\n",i->addr,i->key,(i+1)->addr);
	if(i != vect.end())
		printf("%05d %d -1\n",i->addr,i->key);

	return 0;
}