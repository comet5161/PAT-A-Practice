#include<iostream>
#include<string>
#include<string.h>

bool flag[256];

using namespace std;

int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	memset(flag,true,sizeof(flag));
	for(auto i = b.begin(); i != b.end(); ++i)
		flag[*i] = false;
	for(auto i = a.begin(); i != a.end(); ++i)
		if(flag[*i])
			printf("%c",*i);
	cout << endl;
	return 0;
}