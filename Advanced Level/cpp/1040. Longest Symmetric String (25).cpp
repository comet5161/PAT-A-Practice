//动态规划解法：
//http://blog.csdn.net/xtzmm1215/article/details/38746233

#include<iostream>
#include<string>

using namespace std;
char str[1002];

int symOdd(char *c,int x,int len)
{
	int i = x - 1;
	int j = x + 1;
	for(;i >= 0 && j < len; --i,++j)
		if(c[i] != c[j])
			break;
	return j - i -1;
}

int symEven(char *c,int x, int len)
{
	int i = x;
	int j = x + 1;
	for(;i >= 0 && j < len; --i,++j)
		if(c[i] != c[j])
			break;
	return j - i - 1;
}

int main()
{
	cin.getline(str,1001);//这里写成1000的话测试点3通不过
	string s = str;
	int len = s.size();
	int max = 0,odd,even;

	for(int k = 0; k < len; ++k)
	{
		odd = symOdd(str,k,len);
		even = symEven(str,k,len);
		if(odd > max)
			max = odd;
		if(even > max)
			max = even;
	}

	cout << max << endl;
	return 0;
}