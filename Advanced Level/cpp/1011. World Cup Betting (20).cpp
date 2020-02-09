#include<iostream>
#include<map>
#include<stdio.h>
#include<iomanip>

using namespace std;

int main()
{
	float w,t,l;

	map<float,char ,greater<float>> a,b,c;
	cin >> w >> t >> l;
	a[w] = 'W';
	a[t] = 'T';
	a[l] = 'L';

	cin >> w >> t >> l;
	b[w] = 'W';
	b[t] = 'T';
	b[l] = 'L';

	cin >> w >> t >> l;
	c[w] = 'W';
	c[t] = 'T';
	c[l] = 'L';

	float sum = a.begin()->first * b.begin()->first * c.begin()->first * 0.65 * 2 - 2;
	cout << a.begin()->second << " " << b.begin()->second << " " << c.begin()->second << " ";
	printf("%.2f",sum);

	return 0;
}