//
/*
	if(pos == -1 )
		printf("-1\n");//如果这里写成printf("-1")，即没有换行符，最后一个测试点9会运行超时，不懂为什么。。。
	else
		printf("%05d\n",pos);
*/

#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int pos,next;
	//map<int,char> word;
	map<int,int> nextPos;
	vector<int> a,b;
	char c;
	int n;
	int n1,n2;

	cin >> n1 >> n2 >> n;
	for(int k = 0; k < n; ++k)
	{
		scanf("%d %c %d",&pos,&c,&next);
		//word[pos] = c;
		nextPos[pos] = next;
	}

	while(n1 != -1)
	{
		a.push_back(n1);
		n1 = nextPos[n1];
	}
	while(n2 != -1)
	{
		b.push_back(n2);
		n2 = nextPos[n2];
	}

	pos = -1;
	auto i = a.rbegin();
	auto j = b.rbegin();
	for(; i != a.rend() && j != b.rend(); ++i,++j)
	{
		if(*i != *j)
			break;
		pos = *i;
	}
	if(pos == -1 )
		printf("-1\n");
	else
		printf("%05d\n",pos);

	return 0;
}