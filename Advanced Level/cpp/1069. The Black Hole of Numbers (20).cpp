#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bigger(int x)
{
	vector<int> a;
	for(int k = 0; k < 4; ++k)
	{
		a.push_back(x%10);
		x/=10;
	}
	sort(a.begin(),a.end());
	x = 0;
	for(auto i = a.rbegin(); i != a.rend(); ++i)
		x = x*10 + *i;
	return x;
};

int smaller(int x)
{
	vector<int> a;
	for(int k = 0; k < 4; ++k)
	{
		a.push_back(x%10);
		x/=10;
	}
	sort(a.begin(),a.end());
	x = 0;
	for(auto i = a.begin(); i != a.end(); ++i)
		x = x*10 + *i;
	return x;
};


int main()
{
	int n,x,y,z;
	cin >> n;
	z = n;

	if(z == 0)
	{
		printf("0000 - 0000 = 0000\n");
		return 0;
	}
	bool done = false;
	do 
	{
		x = bigger(z);
		y = smaller(z);
		if(x - y == z && done == true)
			break;
		printf("%04d - %04d = %04d\n",x,y,x - y);
		done = true;
		z = x - y;
	}while( z);

	return 0;
}