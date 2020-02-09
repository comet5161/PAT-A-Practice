#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

class Mouse{
public:
	int id;
	int weight;
	int winCount;//参加比赛次数
	int rank;
	Mouse():winCount(0){}
	friend bool operator < (const Mouse &a, const Mouse &b)
	{
		return a.winCount > b.winCount;
	}
};

int main()
{
	int n,m,k,id;
	vector<int> order;
	int playTimes;
	cin >> n >> m;
	vector<Mouse> mouse(n);
	for(k = 0; k < n; ++k)
	{
		mouse[k].id = k;
		scanf("%d",&mouse[k].weight);
	}
	for(k = 0; k < n; ++k)
	{
		scanf("%d",&id);
		order.push_back(id);
	}

	
	while(order.size() > 1)
	{
		int count = 0;
		vector<int> temp;
		auto winner = order.begin();
		for(auto i = order.begin(); i != order.end(); ++i)
		{
			if(mouse[*i].weight > mouse[*winner].weight)
				winner = i;
			count++;
			if(count == m || i+1 == order.end() )//当前组比完
			{
				count = 0;
				temp.push_back(*winner);//当前组中胜者晋级
				mouse[*winner].winCount++;//胜者胜利次数加1
				winner = i+1;//下一组
			}
		}
		order = temp;
	}
	//最大
	vector<Mouse> rankList = mouse;
	//按胜利的次数排序(多的在前)
	sort(rankList.begin(), rankList.end());
	auto pre = rankList.begin();
	mouse[pre->id].rank = 1;
	for(auto i = rankList.begin(); i != rankList.end(); ++i)
	{
		if(i->winCount == pre->winCount)
			mouse[i->id].rank = mouse[pre->id].rank;
		else
			mouse[i->id].rank = i - rankList.begin() + 1;
		pre = i;
	}

	for(auto i = mouse.begin(); i != mouse.end(); ++i)
	{
		if(i != mouse.begin())
			printf(" ");
		printf("%d",i->rank);
	}
	cout << endl;

	return 0;
}