#include<iostream>
#include<vector>

using namespace std;

//count the maxforward num
int Count(int id,vector< vector<int>> &users,int level)
{
	int count = 0;
	vector<bool> flag(users.size(),false);
	vector<int> que,next;
	que.push_back(id);
	flag[id] = true;
	for(int k = 0; k < level && que.size()>0 ; ++k)
	{
		next.clear();
		for(auto i = que.begin(); i != que.end();++i)//for each user in temp level
			for( auto j = users[*i].begin(); j != users[*i].end(); ++j)
				if(flag[*j] == false)
				{
					flag[*j] = true;
					next.push_back(*j);//next level
				}
		count += next.size();
		que = next;
	}
	return count;
};

int main()
{
	
	int num,level,id;
	cin >> num >> level;
	vector< vector<int> > users(num + 1);
	for(int k = 1; k <= num; ++k)
	{
		int n;
		scanf("%d",&n);
		for(int j = 0; j < n;++j)
		{
			scanf("%d",&id);
			users[id].push_back(k);//user "id" was followed by user "k"
		}
	}
	int query;
	cin >> query;
	for(int k = 0; k < query;++k)
	{
		scanf("%d",&id);
		cout << Count(id,users,level) << endl;
	}

	return 0;
}