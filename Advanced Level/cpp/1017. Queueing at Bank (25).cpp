//在17:01之前到的都能得到服务！而不是服务时间在17:01之前
//
//way1 用vector 存储顾客数据
//
#include<iostream>
#include<set>
//#include<list>
#include<vector>
#include<map>
//#include<queue>
#include<algorithm>
#define INF 999999999
using namespace std;

class Customer{
public:
	long aTime;//arrive time
	long pTime;//process time
	long sTime;//service time
	Customer(long a,long p):aTime(a),pTime(p),sTime(INF){}
	Customer():sTime(INF){}
	friend bool operator < (const Customer& a, const Customer& b)
	{
		return a.aTime < b.aTime;
	}
};

int main()
{
	int N,K;
	int hour,min,sec,pTime;
	char c;
	//map<long,Customer> customer;
	cin >> N >> K;
	auto &customer = *(new vector<Customer>(N));
	int k;
	for(k = 0; k < N; ++ k)
	{
		scanf("%d:%d:%d %d",&hour,&min,&sec,&pTime);
		customer[k].pTime = pTime*60;
		customer[k].aTime = hour*3600+min*60+sec;
	}

	sort(customer.begin(),customer.end());
	//删除到达时间在17:00之后的,(这里好像很费时间，没有这段用时46ms，用这段反而需76ms)
	//auto end = customer.end();
	//int num = 0;
	//for(auto i = customer.begin(); i != customer.end(); ++i,++num)
	//	if(i->aTime > 17 * 3600) 
	//	{
	//		end = i;
	//		break;
	//	}
	//N = num; 

	int done = 0;
	long time = 8*3600 - 1;
	set<long> timeSet;
	auto iter = customer.begin();
	auto *win = new decltype(iter)[K]; 
	auto end = customer.end();

	for(k = 0; k < K; ++k) 
		win[k] = end;
	timeSet.insert( 8*3600);

	while(timeSet.size() > 0)
	{
		time = *timeSet.begin();
		timeSet.erase( timeSet.begin() );
		//pop
		for(k = 0; k < K; ++k)
			if(win[k] != end)
			{
				long sTime = win[k]->sTime;
				long pTime = win[k]->pTime;
				if(time == sTime + pTime)
				{
					//pop
					win[k] = end;
					//++done;
					//push
					if(iter != end && iter->aTime <= time)
					{
						win[k] = iter;
						iter->sTime = time;
						timeSet.insert(iter->sTime + iter->pTime);//下一个服务结束时刻
						++iter;
					}
					else if(iter != end && iter->aTime > time)
						timeSet.insert(iter->aTime);//下一个顾客到达时刻
				}
			}
		//push
		for(k = 0; k < K; ++k)
			if(win[k] == end && iter != end  && iter->aTime <= time)
			{
				iter->sTime = time;
				timeSet.insert(iter->sTime + iter->pTime);//下一个服务结束时刻
				win[k] = iter++;
			}
			else if(win[k] == end && iter != end  && iter->aTime > time)
				timeSet.insert(iter->aTime);//下一个顾客到达时刻
	}
	//print average
	double average = 0;
	int count = 0;
	for(auto i = customer.begin(); i != customer.end(); ++i)
	{
		long st = i->sTime;
		long at = i->aTime;
		long pt = i->pTime;
		if(at <= 17*3600)
		{
			average += st - at;
			++count;
		}
	}
	if(count > 0)
		average /= count;
	printf("%.1f",average/60);

	int jj = 0;
	return 0;
}