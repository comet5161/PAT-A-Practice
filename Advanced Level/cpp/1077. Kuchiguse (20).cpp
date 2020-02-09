#include<iostream>
#include<string>
using namespace std;

string F(string &a,string &b)
{
	string c;
	auto i = a.rbegin();
	auto j = b.rbegin();
	for(; i != a.rend() && j != b.rend(); ++i,++j)
		if(*i == *j)
			c.insert(c.begin(),*i);
		else
			break;
	return c;
};

int main()
{
	string a,b;
	int n;
	scanf("%d\n",&n);
	getline(cin,b);
	for(int k = 1; k < n; ++k)
	{
		getline(cin,a);
		b = F(a,b);
	}

	if(b.size() == 0)
		printf("nai\n");
	else
		cout << b << endl;
	return 0;
}