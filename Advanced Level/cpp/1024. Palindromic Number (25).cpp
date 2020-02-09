#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void Add(vector<int> &a, vector<int> &b)
{
	int c = 0;
	auto i = a.rbegin(); 
	auto j = b.rbegin();
	for(; i != a.rend(); ++j,++i)
	{
		*i = *i + *j + c;
		c = *i / 10;
		*i %= 10;
	}
	if( c != 0 && i != a.rend())
		*i += c;
	else if(c != 0 && i == a.rend())
		a.insert( a.begin(),c);
}

bool Palindromic(vector<int> x)
{
	for(int k = 0; k <= x.size()/2; ++k)
		if( x[k] != x[x.size()-1 - k])
			return false;
	return true;
}

int main()
{
	string s;
	vector<int> v,w;
	int n,k;
	cin >> s >> n;

	for(auto i = s.begin(); i != s.end(); ++i)
		v.push_back(*i%'0'%10);
	if(Palindromic(v))
	{
		cout << s << endl << 0;
		return 0;
	}
	for(k = 1; k <= n; ++k)
	{
		w = v;
		reverse(w.begin(),w.end());
		Add(v,w);
		if(Palindromic(v))
		{
			for(auto i = v.begin(); i != v.end(); ++i)
				cout << *i;
			cout << endl << k;
			break;
		}
	}
	if( k > n)
	{
		for(auto i = v.begin(); i != v.end(); ++i)
			cout << *i;
		cout << endl << n;
	}

	return 0;
}