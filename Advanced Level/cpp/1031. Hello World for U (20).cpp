#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a,b,c;
	int k,n,n1,n2;

	cin >> a;
	n = a.size();
	n1 = (n+2)/3-1;
	n2 = n - n1*2;

	int i = 0;
	int j = n-1;
	for(k = 0; k < n2-2; ++k)
		b.push_back(' ');
	for(k = 0; k < n1; ++k,++i,--j)
		cout << a[i] << b << a[j] << endl;
	for(k = 0; k < n2; ++k,++i)
		cout << a[i];

	return 0;
}