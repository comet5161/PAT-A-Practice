#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>

using namespace std;
int main()
{
	int sum =  0;
	string s;
	cin >> s;
	for(auto i = s.begin(); i != s.end(); ++i)
		sum += *i - '0';
	char word[10][7] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	s.clear();
	
	//s = sum;
	char temp[100];
	
	sprintf(temp,"%d",sum);
	s = temp;

	bool space = false;

	for(auto i = s.begin(); i != s.end(); ++i)
	{
		if(space) cout << " ";
		else space = true;
		cout << word[*i - '0'];
	}
	
	return 0;
}