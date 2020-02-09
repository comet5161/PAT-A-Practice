#include<iostream>
#include<iomanip>
#include<string>
#include<list>

using namespace std;

class Record{
public:
	string id;
	int in;
	int out;
	Record(string id, int in, int out):id(id),in(in),out(out){}
};


int main()
{
	int num;
	int hour,minute,second;
	char c;
	string id;
	list<Record> records;
	cin >> num;
	
	for(int k = 0; k < num; ++k)
	{
		cin >> id >> hour >> c >> minute >> c >> second;
		int in = hour*3600 + minute*60 + second;
		cin >> hour >> c >> minute >> c >> second;
		int out = hour*3600 + minute*60 + second;
		records.push_back( *(new Record(id,in,out)) );
	}

	auto i_in = records.begin();
	auto i_out = records.begin();
	for(auto i = records.begin(); i != records.end(); ++i)
	{
		if(i->in < i_in->in)
			i_in = i;
		if(i->out > i_out->out)
			i_out = i;
		//cout << endl << i->id << " " << i->in << " " << i->out;
	}
	cout << i_in->id << " " << i_out->id;

	return 0;
}