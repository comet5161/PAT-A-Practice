//测试点1，注意选择某课的学生数为0的情况

//直接用map和set做最后个测试点会超时，考虑用哈希表
//http://blog.csdn.net/iaccepted/article/details/39273311




#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>

#define MAX 26*26*26*10+1

using namespace std;
char str[2005],query[40000*5 + 5];
vector<int> sList[MAX];

int Hash(char *name)
{
	return 
		 (name[0]-'A')*26*26*10
		+(name[1]-'A')*26*10
		+(name[2]-'A')*10
		+ name[3]-'0';
};


int main()
{
	int n,m;
	map<string,set<int>> student;
	int id;
	string name;

	cin >> n >> m;
	for(int k = 0; k < m; ++k)
	{
		int j;
		scanf("%d %d\n", &id , &j);
		if(j == 0)
			continue;
		cin.getline(str,2001);
		name = str;
		for(int i = 0; i < j; ++i)
		{
			//student[name.substr(i*5,4)].insert(id);
			sList[Hash(str+i*5)].push_back(id);
		}
	}
	stringstream res;
	cin.getline(query,40000*5+4);
	name = query;
	for(int k = 0; k < n; ++k)
	{
		string temp = name.substr(k*5,4);
		//auto & s = student[temp];
		auto & s = sList[Hash(query+k*5)];
		sort(s.begin(),s.end());
		res << temp << " " << s.size(); 
		for(auto i = s.begin(); i != s.end(); ++i)
			res << " " << *i;
		res << endl;
	}
	cout << res.str();
	return 0;
}