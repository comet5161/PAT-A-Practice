#include<iostream>
#include<map>
#include<list>
#include<iomanip>

using namespace std;

typedef map<int , double,greater<int> >  Map;
void Add(Map& a, Map& b)
{
	for(auto iter = b.begin(); iter != b.end(); )
	{
		auto i = iter++;
		int n = i->first;
		double e = i->second;
		if( a.find(n) != a.end() )
			a[n] += e;
		else
			a[n] = e;

		if(a[n] == 0)
			a.erase(n);//用a.erase(i)会出错！
	}
}

int main()
{
	map<int , double,greater<int> > a,b,c,d;

	int num, n;
	double e;

	cin >> num ;
	for(int k = 0; k < num; ++k)
	{
		cin >> n >> e;
		a[n] = e;
	}
	cin >> num ;
	for(int k = 0; k < num; ++k)
	{
		cin >> n >> e;
		b[n] = e;
	}

	//乘,结果保存在d中；
	for(auto i = b.begin(); i != b.end(); ++i)
	{
		c.clear();
		int n;
		double e;
		for(auto j = a.begin(); j != a.end(); ++j)
		{
			n = i->first + j->first;
			e = i->second * j->second;
			c[n] = e;
		}
		Add(d, c);

	}

	cout << d.size();
	for(auto i = d.begin(); i != d.end(); ++i)
		cout << " " << i->first << " " << fixed << setprecision(1) << i->second ;


	return 0;
}