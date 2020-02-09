#include<iostream>
#include<vector>
#include<set>

#define INF 99999999

using namespace std;

class Edge{
public:
	int city;
	int srcCity;
	int distance;
	int cost;
	Edge(int city,int srcCity,int distance,int cost):city(city),srcCity(srcCity),distance(distance),cost(cost){}

};

class City{
public:
	int id;
	int minDistance;
	bool visited;
	vector<Edge> edge;
	vector<Edge*> parent;
	City():visited(false),minDistance(INF){}
};

vector<int> minPath;
int minCost = INF;
int n,m,s,d;
void CalMinCost(vector<City>& city,vector<int> path,int cost)
{
	int id = *path.rbegin();
	auto & c = city[id];
	//find src city
	if(id == s)
	{
		if(cost < minCost)
		{
			minCost = cost;
			minPath = path;
		}
		return;
	}
	//traverse
	path.push_back(-1);
	for(auto i = c.parent.begin(); i != c.parent.end(); ++i)
	{
		*path.rbegin() = (*i)->srcCity;
		CalMinCost(city,path,cost + (*i)->cost);
	}
}

int main()
{

	int distance,cost,c1,c2;
	int k;
	cin >> n >> m >> s >> d;
	vector<City> city(n);
	for(k = 0; k < n; ++k)
		city[k].id = k;
	for(k = 0; k < m; ++k)
	{
		scanf("%d%d%d%d",&c1,&c2,&distance,&cost);
		city[c1].edge.push_back(*(new Edge(c2,c1,distance,cost)));
		city[c2].edge.push_back(*(new Edge(c1,c2,distance,cost)));
	}

	set<int> que;
	que.insert(s);
	city[s].minDistance = 0;
	while(que.size()> 0)
	{
		int min = INF;
		int idx;
		for( auto i = que.begin(); i != que.end(); ++i)
			if(city[*i].minDistance < min)
			{
				idx = *i;
				min = city[*i].minDistance;
			}
		auto &c1 = city[idx];
		que.erase(idx);
		c1.visited = true;
		//find destination
		if(idx == d)
			break;
		for(auto i = c1.edge.begin(); i != c1.edge.end(); ++i)
		{
			auto &c2 = city[i->city];
			if(c2.minDistance >= c1.minDistance + i->distance)
			{
				if(c2.minDistance > c1.minDistance + i->distance)
					c2.parent.clear();
				c2.minDistance = c1.minDistance + i->distance;
				c2.parent.push_back(&*i);
				if(c2.visited == false)
					que.insert(c2.id);
			}
		}
	}

	vector<int> tempPath;
	tempPath.push_back(d);
	int minDistance = 0;


	CalMinCost(city,tempPath,0);
	bool space = false;
	for(auto i = minPath.rbegin(); i != minPath.rend(); ++i)
	{
		if(space) cout << " ";
		cout << *i;
		space = true;
	}

	cout << " " << city[d].minDistance << " " << minCost;
	return 0;
}