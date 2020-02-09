//对每一个人，所有记录都在同一个月，不同的人的可能不在同一个月！
//没有一个完整记录的customer，不要输出！
//最后一分钟不记费！

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Record{
public:
	long online;
	long offline;
};

class Customer{
public:
	string name;
	int month;
	map<double,bool> rawData;//double表示时间(min),bool:true(on-line),false(off-line)
	vector<Record> record;
};

int price[24];
//计算一个记录的收费
long CalBill( const Record& r)
{
	long sum = 0;
	for(long k = r.online; k < r.offline; ++k)
	{
		long time = k % (24*60);
		time /= 60;
		sum += price[time];
	}
	return sum;
}

int main()
{
	map<string,Customer> customer;
	int k, num;
	int mon,day,hour,min;
	string name,status;
	char c;

	for(k = 0; k < 24; ++k)
		cin >> price[k];
	cin >> num;

	double time;
	for(k = 0; k < num; ++k)
	{
		cin >> name >> mon >> c >> day >> c >> hour >> c >> min >> status;
		time = day*24*60 + hour*60 + min;
		if(status == "on-line")
		{
			customer[name].name = name;
			customer[name].month = mon;
			customer[name].rawData[time] = true;
		}
		else if(status == "off-line")
			customer[name].rawData[time+0.1] = false;//
	}
	//make on-line and off-line to pair
	for(auto i = customer.begin(); i != customer.end(); ++i)
		for(auto ii = i->second.rawData.begin(); ii != i->second.rawData.end(); )
		{
			Record rec;
			auto j = ii++;
			if( ii != i->second.rawData.end() )
				if(j->second == true && ii->second == false)
				{
					rec.online = j->first;
					rec.offline = ii->first;
					i->second.record.push_back(rec);
				}
		}

	vector<Customer> vect;
	for(auto i = customer.begin(); i != customer.end(); ++i)
		vect.push_back(i->second);
	for(auto i = vect.begin(); i != vect.end(); ++i)
	{
		double sum = 0;
		double onePrice;
		if(i->record.size() == 0) continue;//如果没有记录就跳过
		cout << i->name;
		printf(" %02d\n",i->month);
		for(auto ii = i->record.begin(); ii != i->record.end(); ++ii)
		{
			long on = ii->online, off = ii->offline;
			onePrice = CalBill(*ii);
			onePrice /= 100;
			printf("%02d:%02d:%02d ",on/24/60, (on%(60*24))/60, on%60);
			printf("%02d:%02d:%02d %d ", off/24/60, (off%(60*24))/60, off%60, off-on );
			printf("$%.2f\n",onePrice);
			sum += onePrice;
		}
		printf("Total amount: $%.2f\n" ,sum );
	}
	return 0;
}