//注意the maximum total demand of the market 可能不是整数，所以要用double

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Mooncake{
public:
	double price;
	double amount;
	Mooncake(){}
	Mooncake(double price,int amount):price(price),amount(amount){}
	friend bool operator < (const Mooncake &a, const Mooncake &b)
	{
		return a.price/a.amount > b.price/b.amount;
	}
};

int main()
{
	int n;
	double m;

	cin >> n >> m;
	vector<Mooncake> cake(n);
	for(int k = 0; k < n; ++k)
		scanf("%lf",&cake[k].amount);
	for(int k = 0; k < n; ++k)
		scanf("%lf",&cake[k].price);

	sort(cake.begin(),cake.end());

	double sale = 0.0;
	for(auto i = cake.begin(); i != cake.end(); ++i)
	{
		if(m > i->amount)
		{
			sale += i->price;
			m -= i->amount;
		}
		else
		{
			sale += (m/i->amount)*i->price;
			break;
		}
	}
	printf("%.2f\n",sale);

	return 0;
}