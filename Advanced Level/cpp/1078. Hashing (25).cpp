#include<iostream>
#include<vector>
using namespace std;

bool IsPrime(int x)
{
	if(x == 1)
		return false;
	if(x == 2)
		return true;
	for(int k = 2; k <= x/2; ++k)
		if(x%k == 0)
			return false;
	return true;
};

int Index(vector<int> &table, int x)
{
	int size = table.size();
	int i = x%size;
	int j = 0;
	int pre = i;
	while(table[i] > 0)
	{
		++j;
		i = (pre+j*j)%size;
		if(j > 9999)
			return -1;
	}
	table[i] = x;
	return i;
};


int main()
{
	int size,n,index,x;
	cin >> size >> n;

	while( IsPrime(size) == false)
		++size;

	vector<int> table(size,-1);
	for(int k = 0; k < n; ++k)
	{
		scanf("%d",&x);
		index = Index(table,x);
		if(k != 0)
			printf(" ");
		if(index == -1)
			printf("-");
		else
			printf("%d",index);
	}
	printf("\n");
	return 0;
}