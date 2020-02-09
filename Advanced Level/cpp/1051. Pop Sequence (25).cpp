//
/*
Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

Sample Output:
YES
NO
NO
YES
NO

规律：对于序列中的任何一个数，其右边比它小的数字个数必须比栈容量小，且程递减排列

*/

#include<iostream>
#include<vector>
using namespace std;

bool Check(int a[],int n,int m)
{
	int count = 0;
	int h,i,j,k;
	if(n == 1)
		return true;
	for(h = 0; h < n; ++h)
	{
		count = 0;
		j = h;
		i = h+1;
		while(i < n)
		{
			while(i < n && a[i] >= a[h])
				++i;
			if(i >= n)
				break;
			++count;
			if(a[j] < a[i])
				return false;
			j = i;
			i++;
		}
		if(count > m-1)
			return false;
	}
	return true;
}

int main()
{
	int m,n,k,v;
	int a[1001];
	vector<bool> res;
	cin >> m >> n >> k;
	for(int i = 0; i < k; ++i)
	{
		for(int j = 0; j < n; ++j)
			scanf("%d",a+j);

		res.push_back(Check(a,n,m));
	}

	for(auto i = res.begin(); i != res.end(); ++i)
	{
		if(*i)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}