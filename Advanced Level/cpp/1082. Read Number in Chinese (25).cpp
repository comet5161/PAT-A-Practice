//测试点3用例好像是0
//测试点1 10,000,000

#include<iostream>
#include<string>
#include<vector>
using namespace std;

char Unit[9][6] = {"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
char CNum[10][6] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

vector<string> ToChinese(int num)
{
	vector<int> v;
	vector<string> s;
	int x = num;
	if( x == 0)
	{
		s.push_back("ling");
		return s;
	}
	if(x < 0)
		s.push_back("Fu");
	
	for(x = abs(x); x != 0; x/=10)
		v.push_back(x%10);
	
	string pre;
	for(int k = v.size()-1; k >= 0; --k)
	{
		int a = v[k];
		if(a > 0)
		{
			s.push_back(CNum[a]);
			if(k > 0 )//个位单位为1(空),不用显示
				s.push_back(Unit[k]);
		}
		else if( a == 0 && k==4 && num/10000%10000>0)//万
		{
			if(*s.rbegin() == "ling")
				s.pop_back();
			s.push_back(Unit[k]);
		}
		
		else if(a == 0 && (pre != "ling" || (k+1)%4 == 0))//防止多余的ling
			s.push_back("ling");
		pre = CNum[a];
	}
	//删去尾部的ling
	while(*s.rbegin() == "ling")
		s.pop_back();
	return s;
};

int main()
{
	int n;
	cin >> n;
	vector<string> res = ToChinese(n);
	for(auto i = res.begin(); i != res.end(); ++i)
	{
		if(i != res.begin())
			printf(" ");
		cout << *i;
	}
	printf("\n");
	return 0;
}