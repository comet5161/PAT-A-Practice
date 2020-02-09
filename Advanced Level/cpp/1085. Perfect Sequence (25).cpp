//http://blog.csdn.net/andyyang0212/article/details/43890295
//用二分查找
//这里upper_bound用的就是二分查找

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	long long p;
	cin >> n >> p;
	vector<long long> v(n);
	for(int k = 0; k < n; ++k)
		scanf("%lld",&v[k]);
	sort(v.begin(),v.end());
	int max = 0;
	for(int i = 0; i <v.size(); ++i)
	{
		int j = upper_bound(v.begin(),v.end(),v[i]*p) - v.begin();
		if(max < j - i)
			max = j-i;
	}

	printf("%d\n",max);

	return 0;
}