// Simple chopping is assumed without rounding 假定没有四舍五入？
//最后一个测试点 注意00.000这样的数字
#include<iostream>
#include<string>

using namespace std;

int log(const string &s)
{
	bool flag = false;
	//字符串s是不是只含'0'和'.'
	for(auto i = s.begin(); i != s.end(); ++i)
		if( *i != '0' && *i!= '.')
			flag = true;
	if(flag == false)
		return 0;

	int k;
	int pos = s.find('.');
	if(pos == string::npos)
		return s.size();
	for(k = 0; k < s.size(); ++k)
		if(s[k] != '0' && s[k] != '.')
			break;
	if(pos > k)
		return pos - k;
	else
		return pos - k +1;
};

string Significant(string s,int n)
{
	string ret;
	auto i = s.begin();
	while( i != s.end() && (*i == '0' || *i =='.'))
		++i;
	for(; i != s.end(); ++i)
		if(*i != '.')
			ret.push_back(*i);
	while(ret.size() < n)
		ret.push_back('0');
	return ret;
}

int main()
{
	string x,y,a,b;
	int n,i1,i2;
	cin >> n >> x >> y;
	a = Significant(x,n).substr(0,n);
	b = Significant(y,n).substr(0,n);
	i1 = log(x);
	i2 = log(y);
	if( a == b && i1 == i2)
		printf("YES 0.%s*10^%d\n",a.c_str(),i1);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n",a.c_str(),i1,b.c_str(),i2);
	return 0;
}