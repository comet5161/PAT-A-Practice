//ֱ����a+b > c���Ե�2��3ͨ�������ĳ�sum = a + b, sum > c����
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
		if(a > 0 && b > 0 && sum <= 0)//ע����sum <= 0 ��������sum < 0
			flag = true;
		else if( a < 0 && b < 0 && sum >= 0)//ͬ����sum >= 0
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