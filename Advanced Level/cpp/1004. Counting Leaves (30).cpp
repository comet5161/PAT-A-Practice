#include<iostream>
#include<list>
#include<vector>


using namespace std;


class Tree{
public:
	int id;
	int level;
	Tree(int id):id(id),level(1){}
	list<int> child;

};

int N,M;

int main()
{
	int k;
	vector<Tree> tree;
	cin >> N >> M;
	for(k = 1; k <= N; ++k)
		tree.push_back( *(new Tree(k)) );

	for(k = 0; k < M; ++k)
	{
		int id,count;
		cin >> id >> count;
		for(int i = 0; i < count; ++i)
		{
			int child;
			cin >> child;
			tree[id-1].child.push_back(child);
		}
	}

	list<int> level;
	level.push_back(1);
	int space = 0;
	//for each level
	while(level.size() > 0)
	{
		int count = 0;
		list<int> temp;
		for(auto iter = level.begin(); iter != level.end(); ++iter)
		{
			auto child = tree[*iter - 1].child;
			if(child.size() > 0)
			{
				for(auto iter_child = child.begin(); iter_child != child.end(); ++iter_child)
					temp.push_back(*iter_child);
			}
			else
				count ++;

		}
		if(space++ > 0)
			cout << " ";
		cout << count;
		level.clear();
		level = temp;
	}

	//for(auto iter = tree.begin(); iter != tree.end(); ++iter)
	//{
	//	cout << "id: " << iter->id << " ";
	//	for( auto iter2 = iter->child.begin(); iter2 != iter->child.end(); ++iter2)
	//		cout << " " << *iter2;
	//	cout << endl;
	//}

	//system("pause");
	return 0;
}
