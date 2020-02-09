//最后一个测试点5，测试用例中中序序列可能不是有序给出的

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class BinTree{
public:
	int id;
	BinTree* l;
	BinTree* r;
	BinTree():l(0),r(0){}
};

//
bool InVector(vector<int> &v, int x)
{
	for(auto i = v.begin(); i != v.end(); ++i)
		if(*i == x)
			return true;
	return false;
}

//make binary tree
BinTree* MakeTree(vector<int> &pOrder, vector<int> &iOrder)
{
	vector<int> Lp,Li,Rp,Ri;
	if( pOrder.size() == 0 )
		return NULL;
	int id = pOrder[pOrder.size()-1];
	BinTree* node = new BinTree();
	node->id = id;
	//将inorder 序列分到id左右两个序列中
	auto i = iOrder.begin();
	for(; i != iOrder.end(); ++i)
		if(*i == id) break;
	Li.insert(Li.begin(),iOrder.begin(),i);
	Ri.insert(Ri.begin(),++i,iOrder.end());

	//将post order序列同步于inorder，分到左右两个序列
	for(auto i = pOrder.begin(); i != pOrder.end(); ++i)
		if(InVector(Li,*i))
			Lp.push_back(*i);
		else if(InVector(Ri,*i))
			Rp.push_back(*i);
	node->l = MakeTree(Lp,Li);
	node->r = MakeTree(Rp,Ri);
	return node;
}

int main()
{
	int n;
	cin >> n;
	vector<int> pOrder(n),iOrder(n);
	for(int k = 0; k < n; ++k)
		cin >> pOrder[k];
	for(int k = 0; k < n; ++k)
		cin >> iOrder[k];
	
	BinTree* root = MakeTree(pOrder,iOrder);
	queue<BinTree*> que;
	if(root)
		que.push(root);
	bool space = false;
	//print
	while(!que.empty())
	{
		BinTree* p = que.front();
		que.pop();
		if(p->l != NULL)
			que.push(p->l);
		if(p->r != NULL)
			que.push(p->r);
		if(space == true)
			cout << " ";
		cout << p->id;
		space = true;
	}
	return 0;
}