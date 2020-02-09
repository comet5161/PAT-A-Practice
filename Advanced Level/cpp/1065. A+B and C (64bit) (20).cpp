//直接用a+b > c测试点2和3通不过，改成sum = a + b, sum > c才行
//

#include<iostream>

using namespace std;

int main()
{
	long long a,b,c;
	int n;
	cin >> n;
	bool flag;
	for(int k = 1; k <= n; ++k)
	{
		cin >> a >> b >> c;
		long long sum = a+b;
		if(a > 0 && b > 0 && sum <= 0)//注意是sum <= 0 ，不能用sum < 0
			flag = true;
		else if( a < 0 && b < 0 && sum >= 0)//同样，sum >= 0
			flag = false;
		else
			flag = sum > c;
		if(flag == true)
			printf("Case #%d: true\n",k);
		else
			printf("Case #%d: false\n",k);
	}

	return 0;
}