#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>

#define INF 999999999

using namespace std;

class House;

class Rode{
public:
	int distance;
	House *to;
	Rode(House *to,int distance):to(to),distance(distance){}
	Rode(){}
};

class House{
public:
	int id;
	int minDist;
	bool visited;
	House(){}
	vector<Rode> rodes;
};

//保存一个gas station的相关数据
class StationResult{
public:
	int id;//
	int minDist;//该 station与距其最近的House的距离
	int maxDist;//与距其最远的House的距离
	double averageDist;
};

//获取一个station position的相关数据
void GetResult(vector<House> &house,StationResult &s)
{
	int minDist = INF;
	int maxDist = 0;
	double averageDist = 0;
	auto i = house.begin();
	for(++i; i != house.end(); ++i)
	{
		averageDist += i->minDist;
		if(minDist > i->minDist)
			minDist = i->minDist;
		if(maxDist < i->minDist)
			maxDist = i->minDist;
	}
	averageDist /=(double)(house.size()-1);
	s.averageDist = averageDist;
	s.minDist = minDist;
	s.maxDist = maxDist;

};


int StrToNum(string &s)
{
	int x = 0;
	for(auto i = s.begin(); i != s.end(); ++i)
		x = x*10 + (*i-'0');
	return x;
}

void Dijkstra(House &v)
{
	list<House*> que;
	que.push_back(&v);
	v.visited = true;
	while(que.size() > 0)
	{
		House *p = *que.begin();
		int minDist = p->minDist;
		for(auto i = que.begin(); i != que.end(); ++i)
			if((*i)->minDist < minDist)
			{
				minDist = (*i)->minDist;
				p = *i;
			}
		auto &s1 = *p;
		que.remove(p);
		for(auto i = s1.rodes.begin(); i != s1.rodes.end(); ++i)
		{
			auto &s2 = *(i->to);
			if(s2.visited == false)
				que.push_back(&s2);
			s2.visited = true;
			if(s2.minDist > s1.minDist + i->distance)
				s2.minDist = s1.minDist + i->distance;
		}
	}
};

int main()
{
	int N,M,K,D;
	int distance;
	char c;
	string form,to;
	char form_c[10],to_c[10];
	cin >> N >> M >> K >> D;

	vector<House> house(N+1);
	vector<House> station(M+1);
	for(int k = 0; k < K; ++k)
	{
		scanf("%s %s %d",form_c,to_c,&distance);
		form = form_c;
		to = to_c;
		auto *p1 = &house;
		auto *p2 = &house;
		if(*form.begin() == 'G')
		{
			form.erase(form.begin());
			p1 = &station;
		}
		if(*to.begin() == 'G')
		{
			to.erase(to.begin());
			p2 = &station;
		}

		int s1 = StrToNum(form);
		int s2 = StrToNum(to);
		auto &v1 = *p1;
		auto &v2 = *p2;
		Rode r(&(*p1)[s1],distance);
		v2[s2].rodes.push_back(r);
		r.to = &(*p2)[s2];
		v1[s1].rodes.push_back(r);
	}

	StationResult *best = NULL;

	for(int j = 0; j <= M;++j)
	{
		for(int k = 0; k <= N; ++k)
		{
			house[k].id = k;
			house[k].minDist = INF;
			house[k].visited = false;
		}
		for(int k = 0; k <= M; ++k)
		{
			station[k].id = k;
			station[k].minDist = INF;
			station[k].visited = false;
		}
		station[j].minDist = 0;
		Dijkstra(station[j]);

		StationResult &sr = *(new StationResult);
		sr.id = j;
		GetResult(house,sr);
		if(sr.maxDist <= D)
			if(best == NULL)
				best = &sr;
			else if(sr.minDist > best->minDist)
				best = &sr;
			else if(sr.minDist == best->minDist && sr.averageDist < best->averageDist)
				best = &sr;
	}

	if(best == NULL)
		printf("No Solution\n");
	else
		printf("G%d\n%.1f %.1f\n",best->id,(float)best->minDist,(float)best->averageDist);

	return 0;

}