//解码min时第3、4个字符串不驱分大小写，position从0开始数

#include<iostream>
#include<string>
using namespace std;

//"MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, 
//"THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" 

int main()
{
	string a,b,c,d;
	int hour,min,day;
	char days[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	cin >> a >> b >> c >> d;
	day = -1;
	for(int k = 0; k < a.size() && k < b.size(); ++k)
		if(a[k] == b[k])
			if(day == -1 && a[k] >='A' && a[k] <='G')
				day = a[k] - 'A';
			else if(day != -1 )
				if(a[k] >='0' && a[k] <= '9')
				{
					hour = a[k] - '0';
					break;
				}
				else if(a[k] >= 'A' && a[k] <= 'N')
				{
					hour = a[k] - 'A' + 10;
					break;
				}
	for(int k = 0; k < c.size() && k < d.size(); ++k)
		if( (c[k] >= 'a' && c[k] <= 'z') || (c[k] >= 'A' && c[k] <= 'Z') )
			if(c[k] == d[k])
			{
				min = k;
				break;
			}
	
	printf("%s %02d:%02d\n",days[day],hour,min);

	return 0;
}