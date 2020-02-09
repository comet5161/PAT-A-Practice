#include<iostream>
#include<vector>
#include<algorithm>
#define INF 9999999999
using namespace std;

class PayPair{
public:
	int begin,end,value;
	PayPair():value(0){}
	PayPair(int begin,int end,int value):begin(begin),end(end),value(value){}
	friend bool operator < (const PayPair &a, const PayPair &b)
	{
		if(a.value != b.value)
			return a.value < b.value;
		return a.begin < b.begin;
	}
};

int main()
{
	int n,m,v;
	cin >> n >> m;
	vector<int> chain;
	vector< PayPair > result;
	for(int k = 0; k < n; ++k)
	{
		scanf("%d",&v);
		chain.push_back(v);
	}
	int i,j;
	int size = chain.size();
	int sum = 0;
	int min_cost = INF;
	i = j = 0;
	bool done = false;
	for(i = 0; j <= size ; ++i)
	{
		while(sum < m)
		{
			if(j >= size)
			{
				done = true;
				break;
			}
			sum += chain[j++];
		}
		if(done)
			break;
		if(sum >= m)
		{
			if(sum <= min_cost)
			{
				min_cost = sum;
				int begin = i+1;
				int end = j;
				PayPair p(begin,end,sum);
				result.push_back(p);
			}
			sum -= chain[i];
		}
	}

	sort(result.begin(),result.end());

	auto it = result.begin();
	int min = it->value;
	for(; it != result.end(); ++ it)
	{
		if(it->value > min)
			break;
		printf("%d-%d\n",it->begin,it->end);
		//cout << it->begin << "-" << it->end << endl;//ÓÃcout ³¬Ê±
	}

	return 0;
}