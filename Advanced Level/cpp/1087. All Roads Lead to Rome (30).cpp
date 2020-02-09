#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define MAX 26*26*26
#define INF 999999999
using namespace std;

class City;

class Rode{
public:
	City *to;
	int cost;
	Rode(City *to, int cost):to(to),cost(cost){}
};

class City{
public:
	int id;
	string name;
	int happy,min_cost;
	bool visited;
	vector<Rode> rodes;
	vector<City*> parent;
};

int ToNum(string &s)
{
	return (s[0]-'A')*26*26 + (s[1]-'A')*26 + (s[2]-'A');
};

void Dijkstra(City &src)
{
	vector<City*> que;
	que.push_back(&src);
	src.visited = true;
	src.min_cost = 0;
	while(que.size() > 0)
	{
		auto p1 = que.begin();
		for(auto i = que.begin(); i != que.end(); ++i)
			if((*p1)->min_cost > (*i)->min_cost)
				p1 = i;
		City &c1 = **p1;
		que.erase(p1);
		for(auto i = c1.rodes.begin(); i != c1.rodes.end();++i)
		{
			auto &c2 = *i->to;
			if(c2.min_cost >= c1.min_cost + i->cost)
			{
				if(c2.min_cost > c1.min_cost + i->cost)
					c2.parent.clear();
				c2.min_cost = c1.min_cost + i->cost;
				c2.parent.push_back(&c1);
			}
			if(c2.visited == false)
			{
				que.push_back(&c2);
				c2.visited = true;
			}
		}

	}
};

//
int HappySum(vector<City*> c)
{
	int sum = 0;
	for(auto i = c.begin(); i != c.end(); ++i)
		sum += (*i)->happy;
	return sum;
};

//
vector<City*> bestPath;
int pathNum = 0;
void GetBestPath(City &c, City &src,vector<City*> path)
{
	path.push_back(&c);
	if(c.name == src.name)
	{
		++pathNum;
		if(bestPath.size() == 0)
			bestPath = path;
		else
		{
			if(HappySum(path) > HappySum(bestPath))
				bestPath = path;
			else if(path.size() <bestPath.size())
				bestPath = path;
		}
	}
	else
	{
		for(auto i = c.parent.begin(); i != c.parent.end(); ++i)
			GetBestPath(**i,src,path);
	}

}



int main()
{
	int n,m,cost;
	int idx;
	string src,name,dest;
	cin >> n >> m >> src;
	vector<City> citys(MAX);
	vector<int> idVect;
	idx = ToNum(src);
	citys[idx].happy = 0;
	citys[idx].name = src;
	idVect.push_back(idx);
	//input cities inf
	for(int k = 0; k < n -1; ++k)
	{
		cin >> name;
		idx = ToNum(name);
		citys[idx].name = name;
		scanf("%d",&citys[idx].happy);
		idVect.push_back(ToNum(name));
	}
	//input rodes inf
	for(int k = 0; k < m ;++k)
	{
		string c1,c2;
		
		cin >> c1 >> c2 >> cost;
		int id1 = ToNum(c1);
		int id2 = ToNum(c2);
		Rode r(&citys[id2],cost);
		citys[id1].rodes.push_back(r);
		r.to = &citys[id1];
		citys[id2].rodes.push_back(r);
		
	}

	//init
	for(auto i = idVect.begin(); i != idVect.end(); ++ i)
	{
		auto &c = citys[*i];
		c.min_cost = INF;
		c.visited = false;
	}
	dest = "ROM";
	int d_id = ToNum(dest);
	int s_id = ToNum(src);
	Dijkstra(citys[s_id]);
	vector<City*> path;
	GetBestPath(citys[d_id], citys[s_id],path);
	//print
	printf("%d %d %d %d\n",pathNum,citys[d_id].min_cost,HappySum(bestPath),HappySum(bestPath)/(bestPath.size() - 1));
	for(auto i = bestPath.rbegin(); i != bestPath.rend(); ++i)
	{
		if(i != bestPath.rbegin())
			printf("->");
		cout << (*i)->name;
	}
	printf("\n");
	return 0;
}