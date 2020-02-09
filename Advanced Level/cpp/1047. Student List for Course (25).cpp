//·½·¨Í¬1039

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#define MAX 26*26*26*10+5

using namespace std;

int student[MAX][5];


int Hash(char *c)
{
	int a = 'A';
	return (c[0]-a)*26*26*10+
		(c[1]-a)*26*10+
		(c[2]-a)*10+
		(c[3]-'0');
};

int main()
{
	vector<int> course[2501];
	int n,m;
	char name[5];
	cin >> n >> m;
	for(int k = 0; k < n; ++k)
	{
		int num,id,course_id;
		scanf("%s %d",name,&num);
		id = Hash(name);
		memcpy(student[id],name,5);
		for(int j = 1; j <= num; ++j)
		{
			scanf("%d",&course_id);
			course[course_id].push_back(id);
		}
	}

	for(int k = 1; k <= m; ++k)
	{
		auto &c = course[k];
		sort(c.begin(),c.end());
		printf("%d %d\n",k,c.size());
		for(auto i = c.begin(); i != c.end(); ++i)
			printf("%s\n",student[*i]);

	}


	return 0;
}