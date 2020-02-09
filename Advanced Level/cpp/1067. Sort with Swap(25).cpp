#include<iostream>

using namespace std;



int idx[100000];
int arr[100000];

void sway(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
};
int count = 0;
void sway(int x, int y)
{
	sway(&arr[idx[x]],&arr[idx[y]]);
	sway(&idx[x],&idx[y]);
	++count;
}


int main()
{
	int n,x; 
	cin >> n;
	for(int k = 0; k < n; ++k)
	{
		scanf("%d",&x);
		idx[x] = k;
		arr[k] = x;
	}
	for(int k = 0; k < n; ++k)
	{
		if(idx[k] == k)
			continue;
		if(idx[0] == 0)
			sway(0,arr[k]);
		else
			--k;
		while(idx[0] != 0)
			sway(0,idx[0]);
	}

	cout << count << endl;

	return 0;
}