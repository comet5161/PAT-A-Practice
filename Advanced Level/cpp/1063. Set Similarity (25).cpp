#include<iostream>
#include<set>
#include<vector>
using namespace std;

double Simularity(set<int> &a, set<int> &b)
{
	int c = 0;
	for(auto i = a.begin(); i != a.end(); ++i)
		if(b.find(*i) != b.end())
			++c;
	return (double)c/(double)( a.size() + b.size() - c);
};

int main()
{
	int n,m,t;
	vector< set<int> > x;
	cin >> n;
	for(int k = 0; k < n; k++)
	{
		int a;
		set<int> s;
		scanf("%d",&m);
		for(int j = 0; j < m; ++j)
		{
			scanf("%d",&a);
			s.insert(a);
		}
		x.push_back(s);
	}
	cin >> t;
	for(int k = 0; k < t; ++k)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;
		--b;
		if(x[a].size() < x[b].size())
			printf("%.1f%%\n",Simularity(x[a],x[b])*100);
		else
			printf("%.1f%%\n",Simularity(x[b],x[a])*100);
	}
	return 0;
}