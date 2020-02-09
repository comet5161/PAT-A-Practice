#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<string.h>

using namespace std;


//大数加法
class Number{
private: 
	
public:
	list<long> v;
	const static int radix = 10;//进制数
	Number() {v.push_back(0);}
	Number(long long x){
		while(x != 0){
			v.push_front(x%radix);
			x /= radix;
		}
	}
	Number(string s){
		for(auto i = s.begin(); i != s.end(); ++i)
			v.push_back((*i - '0') % radix);
	}
	Number& Add(const Number& n)
	{
		int c = 0;
		auto &x = this->v;
		auto y = n.v;
		if(y.size() > x.size()){
			auto temp = this->v;
			this->v = y;
			y = temp;
		}
		auto i = x.rbegin();
		auto j = y.rbegin();
		for(; j != y.rend(); ++i,++j){
			*i = *i + *j + c;
			c = *i/radix;
			*i = *i % radix;
		}
		if(c != 0 && i != x.rend())
			*i += c;
		else if(c != 0 && i == x.rend())
			x.push_front(c);
		return *this;
	}
	friend Number operator + (const Number& a, const Number& b)
	{
		Number c = a;
		return c.Add(b);
	}

};

int main()
{

	Number nn(16);
	nn.Add(nn,true);
	string s;

	int v[10];
	memset(v,0,sizeof(v));
	
	cin >> s;
	Number n(s);
	for(auto i = n.v.begin(); i != n.v.end(); ++i) 
		v[*i%10]++;
	n = n + n;
	for(auto i = n.v.begin(); i != n.v.end(); ++i) 
		v[*i%10]--;
	bool yes = true;
	for(int k = 0; k < 10; ++ k)
		if(v[k] != 0)
			yes = false;
	if(yes)
		cout << "Yes\n";
	else
		cout << "No\n";
	for(auto i = n.v.begin(); i != n.v.end(); ++i) 
		cout << *i;
	return 0;
}