#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>

using namespace std;

struct compare{
	bool operator () (const string& a,const string& b)
	{
		string x = a;
		string y = b;
		x.append(b);
		y.append(a);
		return x < y;
	}
};

int main()
{
	multiset<string,compare> mset;
	string str;
	int n;
	cin >> n;
	for(int k = 0; k < n; ++k)
	{
		cin >> str;
		mset.insert(str);
	}

	string res;
	for(auto i = mset.begin(); i != mset.end(); ++i)
		res.append(*i);
	auto i = 0;
	//É¾³ýÇ°ÃæµÄ0
	while(res[i] == '0')++i;
	if(i == res.size())
		cout << '0';
	else
		while(i < res.size())
			printf("%c",res[i++]);
	printf("\n");

	return 0;
}