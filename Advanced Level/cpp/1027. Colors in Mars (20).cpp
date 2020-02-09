#include<iostream>


using namespace std;

int main()
{
	char str[13];
	int a,b,c;
	for(int k = 0; k < 10;++k)
		str[k] = '0' + k;
	str[10] = 'A';
	str[11] = 'B';
	str[12] = 'C';
	cin >> a >> b >> c;

	cout << "#" << str[a/13] << str[a%13] 
	<< str[b/13] << str[b%13] << str[c/13] << str[c%13];

	return 0;
}