//求最长公共子序列
//http://blog.csdn.net/tiantangrenjian/article/details/19921051

#include<iostream>
#include<string.h>

#define MAX 10001
#define MAX_FAV 201
using namespace std;

int favor[MAX_FAV];
int given[MAX];
int len[MAX_FAV][MAX]={0};

int main()
{
	int n,favNum,givNum;
	cin >> n >> favNum ;
	for(int k = 1; k <=favNum; ++k)
		scanf("%d", favor+k);
	cin >> givNum;
	for(int k = 1; k <= givNum; ++k)
		scanf("%d",given+k);

	for(int i = 1; i <= favNum; ++i)
		for(int j = 1; j <= givNum; ++j)
		{
			len[i][j] = len[i-1][j] > len[i][j-1] ? len[i-1][j] : len[i][j-1];
			if(favor[i] == given[j])
				len[i][j] += 1;
		}

	cout << len[favNum][givNum] << endl;

	return 0;
}