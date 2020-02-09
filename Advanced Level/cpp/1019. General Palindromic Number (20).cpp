#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long a,r;
	string s;
	vector<long> v;
	cin >> a >> r;
	while(a > 0){
		v.push_back(a%r);
		a/=r;
	}
	long size = v.size();
	bool yes = true;
	if(v.size() > 1)
		for(int i = 0;i <= size/2; ++i)
			if(v[i] != v[size-1-i])
			{
				yes = false;
				break;
			}
	if(yes == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if(v.size() == 0)
		cout  << "0";
	bool space = false;
	for(auto i = v.rbegin(); i != v.rend(); ++i)
	{
		if(space == true)
			cout << " ";
		cout << *i;
		space = true;
	}
	return 0;
}