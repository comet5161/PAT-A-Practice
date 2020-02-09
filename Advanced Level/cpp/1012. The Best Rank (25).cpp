#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<map>

using namespace std;

class Grade{
public:
	long id;
	int grade[4];
	int rank[4];
	static int sort_i;
	Grade(long id, long c, long m, long e): id(id)
	{
		grade[1] = c;
		grade[2] = m;
		grade[3] = e;
		grade[0] = (c + m + e)/3;
	}
};

struct compare{
	bool operator () (Grade* a,Grade* b )
	{
		return a->grade[ a->sort_i ] > b->grade[ b->sort_i ];
	}
};

int Grade::sort_i = 0;
string type("ACME");

int main()
{
	int N , M;
	long id,c,m,e;
	long grade;
	vector<Grade*> g;
	cin >> N >> M;
	
	for(int k = 0; k < N; ++k)
	{
		cin >> id >> c >> m >> e;
		g.push_back( new Grade(id,c,m,e) );
	}

	long last_grade = -1;
	//sort and record rank
	for(int k = 0; k < 4; ++k)
	{
		(*g.begin())->sort_i = k;//依次对ACME排序
		sort(g.begin(),g.end(),compare());
		last_grade = -1;
		for(auto i = g.begin(); i != g.end(); ++i)
		{
			if( last_grade != (*i)->grade[k])
				(*i)->rank[k] = i - g.begin() + 1;
			else
				(*i)->rank[k] = (*(i-1))->rank[k];
			last_grade = (*i)->grade[k];
		}
	}

	//input id
	vector<long> idList;
	for(int k = 0; k < M; ++k)
	{
		cin >> id;
		idList.push_back(id);
	}
	//vector to map
	map<long,Grade*> grade_map;
	for(auto i = g.begin(); i != g.end(); ++i)
		grade_map[(*i)->id] = *i;

	//print
	for(auto iter_id = idList.begin(); iter_id != idList.end(); ++iter_id)
	{
		auto found = grade_map.find(*iter_id);
		if( found != grade_map.end() )
		{
			long min = 9999999;
			int min_index;
			Grade &pg =  *found->second;
			for(int j = 0; j < 4; ++j)//从ACME中取排名最高的
				if( pg.rank[j] < min)
				{
					min = pg.rank[j];
					min_index = j;
				}
			cout << pg.rank[min_index] << " " << type[min_index] << endl;
		}
		else
			cout << "N/A" << endl;
	}
	return 0;
}