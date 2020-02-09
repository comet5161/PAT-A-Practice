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


class Number{
public:
	string s;
	Number(const string& s):s(s){Format();}
	Number():s("0"){Format();}
	Number(int n){Assign(n);}
	//Assign赋值
	void Assign(string ss)
	{
		s = ss;
		Format();
	}
	void Assign(long a)
	{
		char b;
		s.clear();
		if( a == 0)
			s.push_back((char)0);
		while(a != 0)
		{
			b = a%10;
			a /= 10;
			s.insert(s.begin(), b);
		}
	}
	// ToDecimal
	void Assign(string s, long radix)
	{
		int power = 0;
		Number num(radix), sum(0);
		if(s.size() == 0) return;
		for(auto i = s.rbegin(); i != s.rend(); ++i, ++power)
		{
			Number a(radix),b( CharToNum(*i) );
			a.Power(power);
			sum = sum + ( a * b );
		}
		*this = sum;
	}
	//Format
	void Format()
	{
		for(auto i = s.begin(); i != s.end(); ++i)
			*i = *i % '0' % 10;
	}
	//add
	string& Add(string& a,string b)
	{
		if( a.size() < b.size() )
		{
			string c = a; a = b; b = c;
		}
		auto i = a.rbegin();
		int carry = 0;
		for( auto j = b.rbegin(); j != b.rend(); ++i,++j)
		{
			*i += *j  + carry;
			carry = (*i)/10;
			*i = (*i)%10;
		}
		while(i != a.rend() && carry == 1)
		{
			*i += carry;
			carry = (*i)/10;
			*i = (*i)%10;
			++i;
		}
		if( carry == 1)
			a.insert(a.begin(),(char)1);
	
		return a;
	};
	//multiple
	string& Multiple(string& a,string b)
	{
		char carry = 0;//进位标志
		int power = 0;//十进制位
		string c;
		string d;
		d.push_back('\0');

		for( auto j = b.rbegin(); j != b.rend(); ++j, ++power)
		{
			c = a;
			carry = 0;
			auto i = c.rbegin();
			for(; i != c.rend(); ++i)
			{
				*i = (*i)*(*j) + carry;
				carry = *i / 10;
				*i = *i % 10;
			}
			if( carry > 0)
				c.insert(c.begin(),carry);
			if(c != "\0")
				for(int k = 0; k < power; ++k)
					c.push_back('\0');
			Add(d, c);
		}
		a = d;
		return a;
	};
	//power
	void Power( long n)
	{
		Number a,b("1");
		a = *this;
		for(int k = 0; k < n; ++k)
			b = b * a;
		*this = b;
	}
	// +
	friend  Number operator + (const Number& n1, const Number& n2)
	{
		Number temp = n1;
		temp.Add(temp.s, n2.s);
		return temp;
	};
	// *
	friend Number operator * (const Number& n1, const Number& n2)
	{
		Number temp = n1;
		temp.Multiple(temp.s, n2.s);
		return temp;
	}
	// == 
	friend bool operator == (const Number& n1, const Number& n2)
	{
		return n1.s == n2.s ;
	}
	// print
	void print()
	{
		for(auto i = s.begin(); i != s.end(); ++i)
			cout << (char)(*i + '0');
	}


};




long long aa,bb;

string& AddString(string& a,string b)
{
	if( a.size() < b.size() )
	{
		string c = a; a = b; b = c;
	}
	auto i = a.rbegin();
	int carry = 0;//进位标志
	for( auto j = b.rbegin(); j != b.rend(); ++i,++j)
	{
		*i += *j - '0' + carry;
		carry = (*i - '0')/10;
		*i = (*i - '0')%10 + '0';
	}
	while(i != a.rend() && carry == 1)
	{
		*i += carry;
		carry = (*i - '0')/10;
		*i = (*i - '0')%10 + '0';
		++i;
	}
	if( carry == 1)
		a.insert(a.begin(),'1');
	
	return a;
}


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

	//cout << ToDecimal("1234567890",10);

	//long long i1,i2;
	//cin >> i1 >> i2 ;
	//
	////string s1  , s2 ;
	//char str[100];
	//sprintf(str,"%d",i1);
	//string s1(str);
	//sprintf(str,"%d",i2);
	//string s2(str);
	//cout << i1 + i2 << endl;

	//cout << "string : " << AddString(s1, s2) << endl;

	//Number n1("1000000799999999999999999999"),n2("1234563");

	//n1.print();
	//cout << endl;
	//n1 = n1 + n2;
	//n1.print();

	//cout << endl;
	//n1.Assign(600000);
	//n2.Assign(2000);
	//n1 = n1 * n2;
	//n1.print();

	//cout << endl;
	//n1.Assign(10);
	//n1.Power(6);
	//n1.print();

	//cout << endl;
	//n1.Assign("zzzzzzzzzz",36);
	//n1.print();
	

	//正文

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

	////way2 
	//Number num1,num2;
	////num1.Assign("5",6);
	////num1.print():
	//num1.Assign(a,radix);
	//int min_radix = MinRadix(b);
	//for(long j = min_radix; j <= 100000; ++j)
	//{
	//	num2.Assign(b,j);
	//	if(num1 == num2)
	//	{
	//		cout << j;
	//		return 0;
	//	}
	//	if(num2.s.size() > num1.s.size())
	//		break;
	//}


	cout << "Impossible";
	return 0;
}