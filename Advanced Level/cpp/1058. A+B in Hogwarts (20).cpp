#include<iostream>

using namespace std;


int main()
{
	int a,b,c,i,j,k;
	scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&i,&j,&k);
	c += k;
	b += j;
	a += i;
	b += c/29;
	c %= 29;
	a += b/17;
	b %= 17;
	printf("%d.%d.%d\n",a,b,c);
	return 0;
}
