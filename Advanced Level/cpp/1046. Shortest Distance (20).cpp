#include<iostream>
#include<vector>

using namespace std;

int x[100000+1] = {0};

int main()
{
	int n,sum = 0,last,dist;
	cin >> n;
	for(int k = 1; k < n; ++k)
	{
		scanf("%d",&dist);
		sum += dist;
		x[k+1] = sum;
	}
	scanf("%d",&last);
	sum += last;

	int m,a,b,c,minDist;
	vector<int> res;
	cin >> m;
	for(int k = 0; k < m; ++k)
	{
		scanf("%d%d",&a,&b);
		if(a > b)
			{ c = a; a = b; b = c;}
		minDist = x[b] - x[a];
		if(minDist > sum - minDist)
			minDist = sum - minDist;
		res.push_back(minDist);
	}

	for(auto i = res.begin(); i != res.end(); ++i)
		printf("%d\n",*i);

	return 0;
}