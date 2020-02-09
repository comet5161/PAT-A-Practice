#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Tree{
public:
	int id;
	Tree *left,*right;
	Tree(int id):id(id),left(NULL),right(NULL){}

};

//print
bool space_flag = false;
void PostOrder(Tree * t)
{
	if(t == NULL)
		return;
	PostOrder(t->left);
	PostOrder(t->right);
	if(space_flag == true)
		printf(" ");
	printf("%d",t->id);
	space_flag = true;
};

int main()
{
	int n,id;
	cin >> n;
	string cmd; 
	int count = 0;
	Tree *root,*temp = NULL;
	vector<Tree*> que;
	root = NULL;
	while(count < n)
	{
		cin >> cmd;
		if(cmd == "Push")
		{
			scanf("%d",&id);
			Tree *t = new Tree(id);
			if(root == NULL)
				root = t;
			else 
				if(temp->left == NULL)
					temp->left = t;
				else 
					temp->right = t;
			temp = t;
			que.push_back(t);
		}
		else if(cmd == "Pop")
		{
			temp = *que.rbegin();
			que.pop_back();
			++count;
		}
	}

	PostOrder(root);

	return 0;
}