#include<iostream>
#include<string>

using namespace std;

int StrToNum(string s)
{
	int x = 0;
	int flag = 1;
	if(*s.begin() == '-')
		flag = -1;
	auto i = s.begin();
	for(++i; i != s.end(); ++i)
		x = x*10 +(*i-'0');
	return x*flag;
};

int main()
{
	string s,base,power;
	cin >> s;
	auto i = s.begin();
	bool flag = false;
	for(++i; i != s.end(); ++i)
	{
		if(*i == 'E')
			flag = true;
		else if(flag == false && *i != '.')
			base.push_back(*i);
		else if(flag ==  true)
			power.push_back(*i);
	}
	
	int p = StrToNum(power);
	int x = p;


	if(*s.begin() == '-')
		cout << "-";
	if(x < 0)
	{
		x++;
		for(;x < 0; ++x)
			base.insert(base.begin(),'0');
		cout << "0." << base << endl;
	}
	else
	{
		for(x = p + 1 - base.size();  x > 0;--x)
			base.push_back('0');
		for(int k = 0; k < base.size();++k)
		{
			cout << base[k];
			if(k == p && k != base.size()-1)
				cout << ".";
		}
		cout << endl;
	}


	

	return 0;
}
