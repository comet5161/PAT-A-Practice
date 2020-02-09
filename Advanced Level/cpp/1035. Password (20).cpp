#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>

using namespace std;


int main()
{
	vector<string> name1,name2,pw1,pw2;
	string name,pass;
	int n;
	cin >> n;
	for(int k = 0; k < n; ++k)
	{
		cin >> name >> pass;
		name1.push_back(name);
		pw1.push_back(pass);
	}
	for(int k = 0; k < n; ++k)
	{
		bool flag = false;
		for(auto i = pw1[k].begin(); i != pw1[k].end(); ++i)
		{
			if(*i == '1')
			{*i = '@'; flag = true;}
			else if(*i == '0')
			{*i = '%%'; flag = true;}
			else if(*i == 'l')
			{*i = 'L'; flag = true;}
			else if(*i == 'O')
			{*i = 'o'; flag = true;}
		}
		if(flag)
		{
			name2.push_back(name1[k]);
			pw2.push_back(pw1[k]);
		}

	}

	if(name2.size() == 0)
	{
		if(name1.size() == 1)
			cout << "There is 1 account and no account is modified\n";
		else
			cout << "There are " << name1.size() << " accounts and no account is modified\n";
	}
	else
	{
		cout << name2.size() << endl;
		for(int k = 0; k < name2.size(); ++k)
			cout << name2[k] << " " << pw2[k] << endl;
	}

	return 0;
}