#include<iostream>
#include<map>

using namespace std;

int Prime(int x)
{
	if(x == 1)
		return 1;
	if(x == 2)
		return 2;
	for(int k = 2; k <= x/2; ++k)
		if(x%k == 0)
			return k;
	return x;

}


int main()
{
	map<int,int> m;
	int n,x;
	cin >> n;

	if( n == 1)
	{
		cout << "1=1\n";
		return 0;
	}

	x = n;
	while(x > 1)
	{
		int pr = Prime(x);
		m[pr]++;
		x /= pr;
	}
	printf("%d=",n);
	for(auto i = m.begin(); i != m.end(); ++i)
	{
		if(i != m.begin())
			cout << "*";
		cout << i->first;
		if(i->second > 1)
			cout << "^" << i->second;
	}
	cout << endl;

	return 0;
}