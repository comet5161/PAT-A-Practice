#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
	vector<long long> c1,c2,p1,p2;
	int m,n;
	int v;
	cin >> m;
	for(int k = 0; k < m; ++k)
	{
		scanf("%d",&v);
		if(v > 0)
			c1.push_back(v);
		else if(v < 0)
			c2.push_back(-v);
	}
	cin >> n;
	for(int k = 0; k < n; ++k)
	{
		scanf("%d",&v);
		if(v > 0)
			p1.push_back(v);
		else if(v < 0)
			p2.push_back(-v);
	}
	
	sort(c1.begin(),c1.end());
	sort(c2.begin(),c2.end());
	sort(p1.begin(),p1.end());
	sort(p2.begin(),p2.end());

	long long sum = 0;
	while(!c1.empty() && !p1.empty())
	{
		sum += *c1.rbegin() *  *p1.rbegin();
		c1.pop_back();
		p1.pop_back();
	}

	while(!c2.empty() && !p2.empty())
	{
		sum += *c2.rbegin() *  *p2.rbegin();
		c2.pop_back();
		p2.pop_back();
	}

	cout << sum << endl;

	return 0;
}