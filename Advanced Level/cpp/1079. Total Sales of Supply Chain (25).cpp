#include<iostream>
#include<vector>

using namespace std;



int main()
{
	int n,id;
	double price,total,rate;
	cin >> n >> price >> rate;
	vector< vector<int>> member(n);
	vector<double> amount(n,0);
	vector<double> priceList(n,0);
	for(int k = 0; k <n; ++k)
	{
		int num;
		cin >> num;
		if(num > 0)
		{
			member[k].resize(num);
			for(int j = 0; j < num; ++j)
				scanf("%d",&member[k][j]);
		}
		else
			scanf("%lf",&amount[k]);
	}

	priceList[0] = price;
	vector<int> que;
	que.push_back(0);
	while(que.size() > 0)
	{
		vector<int> next;
		for(auto i = que.begin(); i != que.end(); ++i)
			for(auto j = member[*i].begin(); j != member[*i].end(); ++j)
			{
				priceList[*j] = priceList[*i]*(1+rate/100.0);
				next.push_back(*j);
			}
		que = next;
	}

	total = 0.0;
	for(int k = 0; k < amount.size(); ++k)
		if(amount[k] > 0)
			total += amount[k] * priceList[k];
	printf("%.1lf\n",total);
	return 0;
}