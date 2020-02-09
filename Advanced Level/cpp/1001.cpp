#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int a,b,c;

	cin >> a >> b;
	c = a + b;
	if(c < 0)
	{
		c = -c;
		cout << "-";
	}
	if(c == 0)
	{
		cout << 0;
	}
	else if(c < 1000)
		cout << c;
	else if(c < 1000000)
	{
		cout << c/1000  << ",";
		cout.fill('0');
		cout << setw(3) << (c % 1000);
	}
	else
	{
		cout << c/1000000 << ",";
		cout.fill('0');
		cout << setw(3) << c/1000 % 1000 << ",";
		cout.fill('0');
		cout << setw(3) << (c % 1000);
	}
	system("pause");
	return 0;
}