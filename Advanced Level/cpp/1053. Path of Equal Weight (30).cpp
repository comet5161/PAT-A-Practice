#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Node{
public:
	int id;
	int weight;
	vector<int> child;
	Node(){}
	Node(int id, int weight):id(id),weight(weight){}
};

vector<Node> tree;
int weight[100];
vector<vector<int>> pathList;
int n,m,sum;

struct ListCompare{
	bool operator () (const vector<int> &a, const vector<int> &b)
	{
		//return a.size() < b.size();
		auto i = a.begin();
		auto j = b.begin();
		for(; i != a.end() && j != b.end(); ++i,++j)
		{
			int w1 = tree[*i].weight;
			int w2 = tree[*j].weight;
			if(w1 > w2)
				return true;
			else if(w1 < w2)
				return false;
		}
		return a.size() > b.size();
	}
};

void GetEqualPath(int id ,int weight,vector<int> path)
{
	auto &t = tree[id];
	weight += t.weight;
	path.push_back(id);
	if(t.child.size() == 0 && weight == sum)
	{
		pathList.push_back(path);
		return;
	}
	if(weight > sum)
		return;
	for(auto i = t.child.begin(); i != t.child.end(); ++i)
		GetEqualPath(*i,weight,path);
}

int main()
{
	int k;
	cin >> n >> m >> sum;
	//add node
	for(k = 0; k < n; ++k)
	{
		int w;
		cin >> w;
		Node node(k,w);
		tree.push_back(node);
	}
	//add child
	for(k = 0; k < m; ++k)
	{
		int id,num,child;
		cin >> id >> num;
		for(int j = 0; j < num; ++j)
		{
			cin >> child;
			tree[id].child.push_back(child);
		}
	}

	vector<int> path;
	GetEqualPath(0,0,path);
	sort(pathList.begin(),pathList.end(),ListCompare());
	for(auto i = pathList.begin(); i != pathList.end(); ++i)
	{
		for(auto j = i->begin(); j != i->end(); ++j)
		{
			if(j != i->begin())
				printf(" ");
			printf("%d",tree[*j].weight);
		}
		cout << endl;
	}

	return 0;
}