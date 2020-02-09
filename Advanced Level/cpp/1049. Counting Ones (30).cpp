//
/*
测试用例：3149
f(9)=1
f(40)=14
f(100)=21
f(3000)=1900

9:f(9) = 1
49: f(40) + f(9) = 15
149: f(100) + 49 + f(49) = 85
3149: f(3000) + f(149) = 1985

规律：
f(x*10^k) = 
{
	if(x == 1)
		k*10^(k-1)+1;
	else
		10^k + x*k*10^(k-1)
}

对于1abcd类的数字(最高位为1),f(1abcd) = f(10000) + f(abcd) + abcd
对于最高位不为1的数字，f(xabcd) = f(x0000) + f(abcd)

//
*/

#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

//计算1到x*10^k含1的个数
int xEk(int x, int k)
{
	if(x == 1)
		return k*pow((double)10,k-1)+1;
	else
		return pow((double)10,k) + x*k*pow((double)10,k-1);
}

int CountOne(int x)
{
	vector<int> value;
	int count = 0;
	int power;

	if(x == 1)
		return 1;

	while(x != 0)
	{
		value.push_back(x%10);
		x /= 10;
	}
	power = 0;
	x = 0;
	for(auto i = value.begin(); i != value.end(); ++i,++power)
	{
		if(*i == 0)
			continue;
		if(*i == 1)
			count = xEk(1,power) + x + count;
		else
			count += xEk(*i,power);
		x +=  *i*pow(10.0,power);
	}
	return count;
}

int main()
{
	int n = 3149;
	int sum = 0;
	//for(int k = 1; k <= n; ++k)
	//{
	//	int temp = k;
	//	while(temp != 0)
	//	{
	//		if(temp%10 == 1)
	//			sum++;
	//		temp/=10;
	//	}
	//}
	
	//cout << sum << endl;
	//cin >> n;
	int sum2 = CountOne(n);
	cout << sum2 << endl;

	return 0;
}