//先将序列排序，再从两边向中间检索
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> coin;
	int n,m,v;
	cin >> n >> m;
	for(int k = 0; k < n; ++k)
	{
		scanf("%d",&v);
		coin.push_back(v);
	}

	sort(coin.begin(),coin.end());

	int i,j;
	i = 0;
	j = coin.size()-1;
	if(coin[0] > m/2 || coin[j] < m/2)
	{
		cout << "No Solution\n";
		return 0;
	}
	//i,j从两边向中间靠拢
	while(i < j)
	{
		while(i < j && coin[i]+coin[j] > m) 
			--j;
		while(i < j && coin[i]+coin[j] < m)
			++i;
		if(coin[i]+coin[j] == m)
			break;
	}
	if(i >= j)
		cout << "No Solution\n";
	else
		cout << coin[i] << " " << coin[j] << endl;

	return 0;
}