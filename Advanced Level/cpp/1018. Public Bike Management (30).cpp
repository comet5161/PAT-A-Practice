#include<iostream>
#include<vector>
#include<queue>
#include<list>

#define INF 9999999999

using namespace std;

class Rode{
public:
	int station;
	int weight;
	Rode(int s, int w):station(s),weight(w){}
};
class Station{
public:
	int id;
	int val;
	int distance;
	bool known;
	vector<Rode> rode;
	vector<int> parent;
	Station():distance(INF),known(false){}
};

void Dijkstra(Station S[], int des, int src)
{
	list<Station*> sList;
	S[src].distance = 0;
	sList.push_back(&S[0]);
	while(sList.size() > 0){
		int min = INF;
		auto idx = sList.end();
		//find next station with min weight
		for(auto i = sList.begin(); i != sList.end(); ++i)
			if( (*i)->distance < min){
				min = (*i)->distance;
				idx = i;
			}
		auto &s1 = **idx;
		s1.known = true;
		//pop
		sList.erase(idx);
		if(s1.id == des)
			break;
		//update stations link to s1
		for(auto i = s1.rode.begin(); i != s1.rode.end(); ++i){
			auto &s2 = S[i->station];
			if(s2.known == true) continue;
			//push
			sList.push_back(&s2);
			if(s2.distance > s1.distance + i->weight){ 
				s2.parent.clear();
				s2.parent.push_back(s1.id);
				s2.distance = s1.distance + i->weight;
			}
			else if(s2.distance == s1.distance + i->weight){
				s2.parent.push_back(s1.id);
				s2.distance = s1.distance + i->weight;
			}
		}
		//
	}
}

int Cmax,N,Sp,rodes;
long minBack = INF, minSent = INF;
vector<int> bestPath;

void BestPath(vector<int> path, Station s[], int temp, int src)
{
	int sent = 0, back = 0, x;
	for(auto i = path.rbegin(); i != path.rend(); ++i){
		x = s[*i].val - Cmax/2;
		if( x < 0 && back > 0){
			if(x + back > 0){
				back += x;
				x = 0;
			}
			else {
				x += back;
				back = 0;
			}
		}
		if( x < 0)
			sent += -x ;
		else
			back += x;
	}
	if(rodes > 200 && sent > minSent) return;//ºÙ÷¶
	if(temp == src){
		if(sent < minSent || (sent == minSent && back < minBack)){
			minBack = back;
			minSent = sent;
			bestPath = path;
		}
	}
	else{
		path.push_back(temp);
		for(auto i = s[temp].parent.begin(); i != s[temp].parent.end(); ++i)
		{
			BestPath(path,s,*i,src);
		}
	}
}

int main()
{
	
	int s1,s2,weight;
	cin >> Cmax >> N >> Sp >> rodes;
	Station station[501];
	int k;
	station[0].id = 0;
	station[0].val = Cmax/2;
	for(k = 1; k <= N; ++k)
	{
		cin >> station[k].val;
		station[k].id = k;
	}
	for(k = 0; k < rodes; ++k)
	{
		cin >> s1 >> s2 >> weight;
		station[s1].rode.push_back(*(new Rode(s2,weight)));
		station[s2].rode.push_back(*(new Rode(s1,weight)));
	}
	Dijkstra(station, Sp, 0);
	vector<int> path;

	BestPath(path,station,Sp, 0);

	cout << minSent << " 0";
	for(auto i = bestPath.rbegin(); i != bestPath.rend(); ++i)
		cout << "->" << *i;
	cout << " " << minBack;
	return 0;
}