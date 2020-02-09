#include<iostream>
#include<list>
#include<string>
#include<math.h>

#include<sstream>
#include<string.h>
#include<stdio.h>


using namespace std;

int CharToNum( char c);
int MinRadix(string a);

long long aa,bb;

int CharToNum( char c)
{
	if( c >= '0' && c <= '9')
		return c - '0';
	if(c >= 'a' && c <= 'z')
		return 10 + c - 'a';
	return -1;
}

long long Power(int a, long n, long long radix)
{
	long long r = 1;
	for(int k = 1; k < n; ++k)
		r *= radix;
	r *= a;
	return r;
}

long long ToDecimal(string a, long long radix, bool stop = true)
{
	long long ret = 0;
	long index = 0;
	for(auto i = a.rbegin(); i != a.rend(); ++i)
	{
		ret += Power( CharToNum(*i), ++index, radix);
		if(stop == true && ret > aa)
			return ret;
	}
	return ret;
}

int MinRadix(string a)
{
	int r = 0;
	for(auto i = a.begin(); i != a.end(); ++i)
	{
		if(CharToNum(*i) > r)
			r = CharToNum(*i);
	}
	return r + 1;
}

int main()
{
	//ÕýÎÄ

	int k;
	string a,b;
	long long tag,radix;
	cin >> a >> b >> tag >> radix;

	if(a == "1" && b == "1" )
	{
		cout << 2;
		return 0;
	}
	if(a == b)
	{
		cout << radix;
		return 0;
	}
	if( a.size() == 1 && b.size() == 1 )
	{
		cout << "Impossible";
		return 0;
	}
	if( tag == 2)
	{
		string c = a;
		a = b;
		b = c;
	}

	////way1
	
	aa = ToDecimal(a, radix,false);
	long long minRadix = MinRadix(b);
	long long  b_radix = minRadix;
	bb = ToDecimal(b, b_radix);
	if(bb > aa)
	{
		cout << "Impossible";
		return 0;
	}
	if( bb == aa)
	{
		cout << b_radix;
		return 0;
	}
	while(bb < aa)
	{
		b_radix *= 2;
		bb = ToDecimal(b, b_radix);
	}

	long long begin = b_radix/2;
	long long end = b_radix;
	long long mid = (begin + end)/2;
	while(begin <= end)
	{
		bb = ToDecimal(b, mid);
		if(aa == bb)
		{
			cout << mid;
			return 0;
		}
		else if( bb > aa )
			end = mid - 1;
		else if( bb < aa)
			begin = mid + 1;
		mid = (begin + end)/2;
	}

	cout << "Impossible";
	return 0;
}