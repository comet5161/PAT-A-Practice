//最后一个测试点3是测试id是0开头的情况

#include<iostream>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#define MAX_SIZE 101

using namespace std;

class Node{
public:
	int place;
	int placeRank;
	int grade;
	int rank;
	long long id;
	Node(){}
	Node(long long id,int p, int g):id(id),place(p),grade(g){}
};

 bool Compare(const Node* a, const Node* b)
{
	if( a->grade != b->grade)
		return a->grade > b->grade;
	return a->id < b->id;
}

int main()
{
	int n,m;
	long long id;
	vector<Node*> w;
	int grade;
	cin >> n;
	for(int k = 1; k <= n; ++k)
	{
		//vector<Node*> v;
		cin >> m;
		for(int j = 0; j < m; ++j)
		{
			cin >> id >> grade;
			Node *node = new Node(id,k,grade);
			w.push_back(node);
			//v.push_back(node);
		}
		//sort(v.begin(),v.end(),Compare);
		//auto pre = v.begin();
		//(*pre)->placeRank = 1;
		//for(auto i = pre+1; i != v.end(); ++i)
		//{
		//	if((*i)->grade == (*pre)->grade)
		//		(*i)->placeRank = (*pre)->placeRank;
		//	else
		//		(*i)->placeRank = i - v.begin() + 1;
		//	pre = i;
		//}
		//w.insert(w.end(),v.begin(),v.end());
	}

	map<int,Node*> preMap;
	map<int,int> rank;
	sort(w.begin(),w.end(),Compare);
	Node* pre = new Node(-1,-1,-1);
	for(auto i = w.begin(); i != w.end(); ++i)
	{
		if((*i)->grade == (pre)->grade)
			(*i)->rank = (pre)->rank;
		else
			(*i)->rank = i - w.begin() + 1;

		int p = (*i)->place;
		rank[p]++;
		if(preMap.find(p) == preMap.end()){//
			preMap[p] = *i;
			(*i)->placeRank = 1;
		}

		else 
		{
			if((*i)->grade == preMap[p]->grade)
				(*i)->placeRank = preMap[p]->placeRank;
			else
				(*i)->placeRank = rank[p];
			preMap[p] = *i;
		}
		pre = *i;
	}

	cout << w.size() << endl;
	for(auto i = w.begin(); i != w.end(); ++i)
	{
		printf("%013lld",(*i)->id); 
		printf(" %d %d %d\n",(*i)->rank,(*i)->place ,(*i)->placeRank);
	}

	return 0;
}