//��17:01֮ǰ���Ķ��ܵõ����񣡶����Ƿ���ʱ����17:01֮ǰ
//
//way1 ��map �洢�˿�����
//
#include<iostream>
#include<set>
//#include<list>
#include<map>
//#include<queue>
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
	map<long,Customer> customer;
	cin >> N >> K;
	int k;
	for(k = 0; k < N; ++ k)
	{
		scanf("%d:%d:%d %d",&hour,&min,&sec,&pTime);
		long t = hour*3600+min*60+sec;
		pTime *= 60;
		customer[t] = *(new Customer(t,pTime));
	}

	//ɾ������ʱ����17:00֮���,(�������ܷ�ʱ�䣬û�������ʱ46ms������η�����76ms)
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
	auto end = customer.end();
	auto *win = new decltype(iter)[K]; 

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
				long sTime = win[k]->second.sTime;
				long pTime = win[k]->second.pTime;
				if(time == sTime + pTime)
				{
					//pop
					win[k] = end;
					//++done;
					//push
					if(iter != end && iter->second.aTime <= time)
					{
						win[k] = iter;
						iter->second.sTime = time;
						timeSet.insert(iter->second.sTime + iter->second.pTime);//��һ���������ʱ��
						++iter;
					}
					else if(iter != end && iter->second.aTime > time)
						timeSet.insert(iter->second.aTime);//��һ���˿͵���ʱ��
				}
			}
		//push
		for(k = 0; k < K; ++k)
			if(win[k] == end && iter != end  && iter->second.aTime <= time)
			{
				iter->second.sTime = time;
				timeSet.insert(iter->second.sTime + iter->second.pTime);//��һ���������ʱ��
				win[k] = iter++;
			}
			else if(win[k] == end && iter != end  && iter->second.aTime > time)
				timeSet.insert(iter->second.aTime);//��һ���˿͵���ʱ��
	}
	//print average
	double average = 0;
	int count = 0;
	for(auto i = customer.begin(); i != customer.end(); ++i)
	{
		long st = i->second.sTime;
		long at = i->second.aTime;
		long pt = i->second.pTime;
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