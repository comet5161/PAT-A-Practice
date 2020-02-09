//注意，最小质数是2；1和0不是

#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

bool IsPrime(int x)
{
	if(x == 1) return false;
	if(x == 0) return false;
	for(int k = 2; k <= x/2; ++k)
		if( x % k == 0) return false;
	return true;
}

int Reverse(int x,int radix)
{
	int ret = 0;
	string str;
	int power = 1;
	while(x > 0)
	{
		str.push_back( (char)(x%radix) );
		x /= radix;
	}
	for(auto i = str.rbegin(); i != str.rend(); ++i)
	{
		ret += *i * power;
		power *= radix;
	}
	return ret;
}

int main()
{
	int n,d;
	vector<int> radix;
	vector<int> num;
	scanf("%d",&n);
	while(n >= 0)
	{
		scanf("%d",&d);
		radix.push_back(d);
		num.push_back(n);
		scanf("%d",&n);
	}
	for(int k = 0; k < num.size(); ++k)
	{ 
		int a = num[k];
		int r = radix[k];
		if( IsPrime(a) && IsPrime(Reverse(a,r)) )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}