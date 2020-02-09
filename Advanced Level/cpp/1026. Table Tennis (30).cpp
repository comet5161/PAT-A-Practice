//不超过2小时，测试点4
//for vip player，choose vip table first
//for ordinary player，choose the minest index table
//
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define INF 999999999

using namespace std;

class Player{
public:
	int id;
	int aTime,dTime,sTime,vip;//arrive,dur,serive time
	Player():sTime(INF){}
	Player(int aTime,int dTime, int vip):aTime(aTime),dTime(dTime),vip(vip),sTime(INF){}
	friend bool operator < (const Player& a, const Player& b)
	{
			return a.aTime < b.aTime;
	}
};

class Table{
public:
	int id;
	int vip;
	int sNum;//served num
	Player* player;
	Table():player(NULL),sNum(0){}
	Table(int id,int vip,Player* p):id(id),vip(vip),sNum(0),player(p){}
	friend bool operator < (const Table& a, const Table& b){
		if(a.vip != b.vip)
			return a.vip > b.vip;
		return a.id < b.id;
	}
};

struct WaitSort{
	bool operator () (const Player* a, const Player* b)
	{
		return a->aTime < b->aTime;
	}
};

bool SortByServeTime(const Player& a, const Player& b)
{
	if(a.sTime != b.sTime)
		return a.sTime < b.sTime;
	return a.aTime < b.aTime;
}

int main()
{
	int k,n,tableNum,vipTableNum,hour,min,sec,dur,pri;
	vector<Player> player;
	vector<Table> table;
	vector<int> vipTableIndex;
	
	//player
	cin >> n;
	for(k = 0; k < n; ++k){
		scanf("%d:%d:%d %d %d\n",&hour,&min,&sec,&dur,&pri);
		dur = dur<=120?dur:120;//不超过2小时，测试点4
		player.push_back( *(new Player(hour*3600+min*60+sec, dur*60,pri)) );
		player.rbegin()->id = k+1;
	}
	sort(player.begin(),player.end());
	//table
	cin >> tableNum;
	for(k = 1; k <= tableNum; ++k)
		table.push_back(*(new Table(k,0,NULL)));	
	//vip table
	cin >> vipTableNum;
	for(k = 0; k < vipTableNum; ++k){
		int id;
		cin >> id;
		table[id-1].vip = 1;
		vipTableIndex.push_back(id-1);
	}
	//open
	set<Player*,WaitSort> waitQue,vipWaitQue;
	set<int> timeSet;
	timeSet.insert(8*3600);
	int done = 0;
	auto pIter = player.begin();

	while(done < player.size())
	{
		int time = *timeSet.begin();
		timeSet.erase(timeSet.begin());
		//collect aviliable table
		for(auto i = table.begin(); i != table.end(); ++i)
			if(i->player != NULL && i->player->sTime + i->player->dTime == time)
			{
				if(i->player->sTime < 21*3600)
					i->sNum++;
				i->player = NULL;
				done++;
			}
		//all done;
		if(done == player.size())
			break;
		//add waitting player
		for(; pIter != player.end(); ++pIter){
			if(pIter->aTime <= time)
			{
				waitQue.insert(&*pIter);
				if(pIter->vip == 1)
					vipWaitQue.insert(&*pIter);
			}
			else
				break;
		}
		//wait for next coming player
		if(pIter != player.end() && pIter->aTime > time)
			timeSet.insert(pIter->aTime);

		//if there are no player waitting now, wait until next player comes
		if(waitQue.size() == 0)
		{
			if(pIter != player.end())
				timeSet.insert(pIter->aTime);
			continue;
		}
		//assign vip table to vip player
		for(auto i = vipTableIndex.begin(); i != vipTableIndex.end(); ++i)
			if(table[*i].player == NULL)
				if(vipWaitQue.size() > 0)
				{
					Player* p = *vipWaitQue.begin();
					p->sTime = time;
					table[*i].player = p;
					timeSet.insert(p->sTime + p->dTime);
					waitQue.erase(p);
					vipWaitQue.erase(p);
				}
				else
					break;
		//assign ordinary table to normal player
		for(auto i = table.begin(); i != table.end(); ++i)
			if(i->player == NULL)
				if(waitQue.size()>0){
					Player* p = *waitQue.begin();
					p->sTime = time;
					i->player = p;
					timeSet.insert(p->sTime + p->dTime);
					waitQue.erase(p);
					if(p->vip == 1)
						vipWaitQue.erase(p);
				}
				else
					break;
	}
	//sort by serve time
	sort(player.begin(),player.end(),SortByServeTime);

	for(auto i = player.begin(); i != player.end(); ++i)
	{
		if(i->sTime >= 21*3600)
			continue;
		printf("%02d:%02d:%02d ",i->aTime/3600,i->aTime%3600/60,i->aTime%60);
		printf("%02d:%02d:%02d ",i->sTime/3600,i->sTime%3600/60,i->sTime%60);
		cout << (i->sTime - i->aTime+30)/60 << endl;//四舍五入rounded up to an integer minute(s).
	}
	bool space = false;
	for(auto i = table.begin(); i != table.end(); ++i)
	{
		if(space)
			cout << " ";
		cout << i->sNum;
		space = true;
	}

	return 0;
}