#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string src,act;
	cin >> src >> act;
	transform(src.begin(),src.end(),src.begin(),::toupper);
	transform(act.begin(),act.end(),act.begin(),::toupper);
	vector<bool> flag(128,false);
	for(auto i = act.begin(); i != act.end(); ++i)
		flag[*i] = true;
	for(auto i = src.begin(); i != src.end(); ++i)
		if(flag[*i] == false)
		{
			printf("%c",*i);
			flag[*i] = true;
		}
	printf("\n");
	return 0;
}