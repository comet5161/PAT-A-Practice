#include<iostream>
#include<vector>
using namespace std;

class Tree{
public:
	int value;
	Tree* left;
	Tree *right;
	Tree():left(NULL),right(NULL){}
	Tree(int value):value(value),left(NULL),right(NULL){}
};

int a[1002];
vector<int> postOrder;


//build binary tree
Tree* BuildTree(int a[],int n)
{
	Tree *left,*right;
	Tree *root = NULL;
	if(n == 1)
		return new Tree(a[0]);
	if(n == 2)
	{
		root = new Tree(a[0]);
		if(a[1] >= a[0])
			root->right = BuildTree(a+1,1);
		else
			root->left = BuildTree(a+1,1);
		return root;
	}
	if(n == 3)
	{
		root = new Tree(a[0]);
		if(a[0] > a[1] && a[0] > a[2])//all right
			root->left = BuildTree(a+1,2);
		else if(a[0] <= a[1] && a[0] <= a[2])//all left
			root->right = BuildTree(a+1,2);
		else if( a[1] < a[2])//one left one right
		{
			root->left = BuildTree(a+1,1);
			root->right = BuildTree(a+2,1);
		}
		else
		{
			delete [] root;
			root = NULL;
		}
		return root;
	}

	int i = 1, j = n - 1;
	while(i < n && a[i] < a[0] )++i;
	while(j > 0 && a[j] >= a[0])--j;
	if( i == n)
	{
		left = BuildTree(a+1,n-1);
		if(left == NULL)
			return NULL;
		root = new Tree(a[0]);
		root->left = left;
	}
	else if(j == 0)
	{
		right = BuildTree(a+1,n-1);
		if(right == NULL)
			return NULL;
		root = new Tree(a[0]);
		root->right = right;
	}
	else if(i == j + 1)
	{
		left = BuildTree(a+1,j);
		right = BuildTree(a+i,n-i);
		if(left == NULL || right == NULL)
			return NULL;
		root = new Tree(a[0]);
		root->left = left;
		root->right = right;
	}

	return root;

};

//build binary tree mirror image
Tree* BuildTreeMirror(int a[],int n)
{
	Tree *left,*right;
	Tree *root = NULL;
	if(n == 1)
		return new Tree(a[0]);
	if(n == 2)
	{
		root = new Tree(a[0]);
		if(a[1] < a[0])
			root->right = BuildTree(a+1,1);
		else
			root->left = BuildTree(a+1,1);
		return root;
	}
	if(n == 3)
	{
		root = new Tree(a[0]);
		if(a[0] <= a[1] && a[0] <= a[2])//all left
			root->left = BuildTree(a+1,2);
		else if(a[0] > a[1] && a[0] > a[2])//all right
			root->right = BuildTree(a+1,2);
		else if( a[1] > a[2])//one left one right
		{
			root->left = BuildTree(a+1,1);
			root->right = BuildTree(a+2,1);
		}
		else
		{
			delete [] root;
			 root = NULL;
		}
		return root;
	}

	int i = 1, j = n - 1;
	while(i < n && a[i] >= a[0] )++i;
	while(j > 0 && a[j] < a[0])--j;
	if( i == n)
	{
		left = BuildTree(a+1,n-1);
		if(left == NULL)
			return NULL;
		root = new Tree(a[0]);
		root->left = left;
	}
	else if(j == 0)
	{
		right = BuildTree(a+1,n-1);
		if(right == NULL)
			return NULL;
		root = new Tree(a[0]);
		root->right = right;
	}
	else if(i == j + 1)
	{
		left = BuildTreeMirror(a+1,j);
		right = BuildTreeMirror(a+i,n-i);
		if(left == NULL || right == NULL)
			return NULL;
		root = new Tree(a[0]);
		root->left = left;
		root->right = right;
	}

	return root;

};

void GetPostOrder(Tree *root)
{
	if(root == NULL)
		return ;
	if(root->left)
		GetPostOrder(root->left);
	if(root->right)
		GetPostOrder(root->right);
	postOrder.push_back(root->value);
}

int main()
{
	//vector<int> a;
	int n,v;
	cin >> n;
	for(int k = 0; k < n; ++k)
		scanf("%d",a+k);
	
	Tree* tree = BuildTree(a,n);
	if(tree == NULL)
		tree = BuildTreeMirror(a,n);
	if(tree == NULL)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		GetPostOrder(tree);
		bool space = false;
		for(auto i = postOrder.begin(); i != postOrder.end(); ++i)
		{
			if(space)
				cout << " ";
			cout << *i;
			space = true;
		}
		cout << endl;
	}

	


	return 0;
}