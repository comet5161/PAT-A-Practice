#include<iostream>
#include<iomanip>
#include<map>

using namespace std;

int main()
{
	int k,n,num;
	double a;
	map<int,double,greater<int>> p1,p2,p3;
	cin >> num;
	for(k = 0; k < num; ++k)
	{
		cin >> n >> a;
		p1[n] = a;
	}
	cin >> num;
	for(k = 0; k < num; ++k)
	{
		cin >> n >> a;
		p2[n] = a;
	}

	for(auto i = p2.begin(); i != p2.end(); ++i )
	{
		int key = i->first;
		if( p1.find(key) != p1.end() )
		{
			p1[key] += p2[key];
			if( p1[key] == 0.0 )
				p1.erase(key);
		}
		else
			p1[i->first] = p2[i->first];
	}

	cout << p1.size();
	for(auto i = p1.begin(); i != p1.end(); ++i)
		cout << " " << i->first << " " << fixed << setprecision(1) << i->second;

	return 0;

}