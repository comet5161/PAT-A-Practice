#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> card(55),temp(55),order(55);
	int j,k;
	for(k = 1; k < 55; ++k)
		card[k] = k;
	cin >> n;
	for(k = 1; k <= 54; ++k)
		scanf("%d",&order[k]);
	for(k = 0; k < n; ++k)
	{
		for(j = 1; j <= 54; ++j)
		{
			temp[ order[j] ] = card[j];
		}
		card = temp;
	}
	bool space = false;
	auto i = card.begin();
	for(++i; i != card.end(); ++i)
	{
		if(space)
			cout << " ";
		if(*i == 53)
			cout << "J1";
		else if(*i == 54)
			cout << "J2";
		else if(*i<=13)
			cout << "S" << (*i-1)%13+1;
		else if(*i <= 26)
			cout << "H" << (*i-1)%13+1;
		else if(*i <= 39)
			cout << "C" << (*i-1)%13+1;
		else
			cout << "D" << (*i-1)%13+1;
			space = true;
	}


	return 0;
}