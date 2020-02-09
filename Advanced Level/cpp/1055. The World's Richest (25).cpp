/*
//为防止超时，相同年龄的只保存前100名
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Person{
public:
	string name;
	int age,worth;
	int rank;
	Person(){}
	Person(string name,int age, int worth):name(name),age(age),worth(worth){}
};

//对两个person 进行比较
struct WorthCompare{
	bool operator () (const Person *a, const Person *b)
	{
		if(a->worth != b->worth)
			return a->worth > b->worth;
		if(a->age != b->age)
			return a->age < b->age;
		return a->name < b->name;
	}
};

//将两个有序(递减)vector 合并成一个有序vector
vector<Person*> MergeVector(const vector<Person*> &a,const vector<Person*> &b, int limit = 100)
{
	vector<Person*> c;
	auto i = a.begin();
	auto j = b.begin();
	while( i != a.end() && j != b.end())
	{
		if( (*i)->rank < (*j)->rank )
			c.push_back(*i++);
		else
			c.push_back(*j++);
		if(c.size() >= limit)
			return c;
	}
	while(i != a.end())
	{
		c.push_back(*i++);
		if(c.size() >= limit)
			return c;
	}
	while(j != b.end())
	{
		c.push_back(*j++);
		if(c.size() >= limit)
			return c;
	}
	return c;
};

int main()
{
	int n,m;
	int age,worth;
	char name[10];
	vector<Person*> person;
	vector< vector<Person*> > ageList(201);
	vector<int> rank, low,high;
	cin >> n >> m;
	//get person information
	for(int k = 0; k < n; ++k)
	{
		scanf("%s %d %d",name,&age,&worth);
		person.push_back(new Person(name,age,worth));
	}

	sort(person.begin(),person.end(),WorthCompare());
	//相同年龄按worth从高到低放到同一列表,超过100个后忽略
	for(auto i = person.begin(); i != person.end(); ++i)
	{
		auto &p = **i;
		p.rank = i - person.begin() + 1;
		if( ageList[p.age].size() > 100)
			continue;
		ageList[p.age].push_back(*i);
	}

	//get query
	for(int k = 0; k < m; ++k)
	{
		int r,l,h;
		scanf("%d %d %d",&r,&l,&h);
		rank.push_back(r);
		low.push_back(l);
		high.push_back(h);
	}
	for(int k = 0; k < rank.size(); ++k)
	{
		int lowAge = low[k];
		int highAge = high[k];
		int count = rank[k];
		vector<Person*> result = ageList[lowAge];
		for(int j = lowAge + 1; j <= highAge; ++j)
			result = MergeVector(result,ageList[j],count);
		printf("Case #%d:\n",k+1);
		if(result.size() == 0)
			printf("None\n");
		else
			for(auto i = result.begin(); i != result.end(); ++i)
				printf("%s %d %d\n",(*i)->name.c_str(),(*i)->age, (*i)->worth);
	}

	return 0;
}