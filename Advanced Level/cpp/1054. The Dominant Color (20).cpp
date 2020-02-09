#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n,m,c;
	map<int,int> count;
	cin >> n >> m; 

	//way1 ��map�����Ե�2��ʱ
	//for(int i = 0; i < n; ++i)
	//	for(int j = 0; j < m; ++j)
	//	{
	//		scanf("%d",&c);
	//		count[c]++;
	//	}
	//int max = 0;
	//int color = 0;
	//for(auto i = count.begin(); i != count.end(); ++i)
	//	if(i->second > max)
	//	{
	//		max = i->second;
	//		color = i->first;
	//	}
	//cout << color << endl;

	//way2 ������һ��������ɫ��ͬ��һ������AC
	int num = 1;
	int color = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			scanf("%d",&c);
			if(c == color)
				num++;
			else
			{
				num--;
				if(num == 0)
				{
					color = c;
					num = 1;
				}
			}

		}
	cout << color << endl;

	return 0;
}