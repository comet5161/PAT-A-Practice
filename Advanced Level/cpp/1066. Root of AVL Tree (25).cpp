#include<iostream>
#include<vector>

using namespace std;

int Max(int x,int y)
{
	return x > y ? x : y;
};

class AVLTree{
public:
	int key;
	int high;
	AVLTree *left,*right;
	AVLTree():high(1),left(NULL),right(NULL){}
	AVLTree(int key):key(key),high(1),left(NULL),right(NULL){}
};

int High(AVLTree* T)
{
	if(T == NULL)
		return 0;
	return T->high;
};

AVLTree* SingleRotateLeft(AVLTree* T)
{
	AVLTree* U = T->left;
	T->left = U->right;
	U->right = T;
	T->high = 1 + Max( High(T->left), High(T->right) );
	U->high = 1 + Max( High(U->left), High(U->right) );
	return U;
};

AVLTree* SingleRotateRight(AVLTree* T)
{
	AVLTree* U = T->right;
	T->right = U->left;
	U->left = T;
	T->high = 1 + Max( High(T->left), High(T->right) );
	U->high = 1 + Max( High(U->left), High(U->right) );
	return U;
};

AVLTree* DoubleRotateLeft(AVLTree* T)
{
	T->left = SingleRotateRight(T->left);
	return SingleRotateLeft(T);
};

AVLTree* DoubleRotateRight(AVLTree* T)
{
	T->right = SingleRotateLeft(T->right);
	return SingleRotateRight(T);
};

AVLTree* Insert(AVLTree* T, int x)
{
	if(T == NULL)
		T = new AVLTree(x);
	else if( x < T->key)
	{
		T->left = Insert(T->left,x);
		if( High(T->left) - High(T->right) == 2)
			if( x < T->left->key)
				T = SingleRotateLeft(T);
			else
				T = DoubleRotateLeft(T);
		
	}
	else if(x > T->key)
	{
		T->right = Insert(T->right,x);
		if( High(T->right) - High(T->left) == 2)
			if( x > T->right->key)
				T = SingleRotateRight(T);
			else
				T = DoubleRotateRight(T);
	}

	T->high = 1 + Max( High(T->left), High(T->right) );
	return T;
};

int main()
{
	int n,key;
	AVLTree* T = NULL;
	cin >> n;
	for(int k = 0; k < n; ++k)
	{
		scanf("%d",&key);
		T = Insert(T,key);
	}

	cout << T->key << endl;

	return 0;
}