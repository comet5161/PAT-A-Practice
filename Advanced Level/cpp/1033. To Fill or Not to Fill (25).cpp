/*

题意：

从S到D一路有N个加油站（油价各异），计算最省钱的加油策略。

分析：

贪心策略：假设现在自己处于A站，要考虑的是A站要不要加油，加多少油的问题。找到当前可达范围内（距离A站cmax*davg）下一个要加油的站B。
A站可达范围内， 分三种情况：

①没有加油站，------- 快到终点了，则加适量油到终点；或者 Impossible，则A站加满油到哪算哪；

②有更便宜的加油站 ------- 则找到第一家比A便宜的加油站B，加尽可能少的油（也可能油够直接开过去）到B站；

③只有价格更高的加油站，------则当下A站加满油，寻找相对最便宜的加油站B 开过去。



偶然看到你的代码，我之前也是测试点4没有通过，现在AC了，我用的测试数据：
50 1300 12 8
7.10 0
7.00 150
7.50 400
8.00 600
7.20 900
7.30 1000
6.00 1250
6.85 1280
-------------------
正确答案是767.50
我错误的原因是到最后第二个加油站6.00 1250的时候本来应该直接开到终点，
可是我却开到了6.85 1280的地方再到终点，我的做法是把最后一个加油站设为price = 0，distance = D。
可能你的原因跟我不一样吧，希望你早日AC，Best Wishes to you~
http://blog.csdn.net/tiantangrenjian/article/details/19175831

*/



#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<string.h>
using namespace std;

class Station{
public:
	int distance;
	bool choose;//是否在该站加油
	bool full;//是否加满
	float price;
	Station():choose(false),full(true){}
	friend bool operator < (const Station& a, const Station& b)
	{
		return a.distance < b.distance;
	}
};


int main()
{
	int cap,dist,ave;
	int num;
	double price;
	int stationDist;
	int running = 0;
	int maxDist;
	vector<Station> station;
	Station s;
	cin >> cap >> dist >> ave >> num;
	maxDist = cap*ave;
	for(int k = 0; k < num; ++k)
	{
		scanf("%f %d",&s.price,&s.distance);
		station.push_back(s);
	}


	sort(station.begin(),station.end());


	auto i = station.begin();
	if(i->distance > 0)
		{
			printf("The maximum travel distance = %.2f",0.00);
			return 0;
		}
	//find if it is impossible to reach the destination
	s.distance = dist;
	s.choose = true;
	s.full = false;
	s.price = 0;//
	station.push_back(s);
	i = station.begin();
	auto j = i + 1;
	for(;j != station.end();++j,++i)
		if(j->distance - i->distance > maxDist)
		{
			printf("The maximum travel distance = %.2f",(double)i->distance + (double)maxDist);
			return 0;
		}
	//station.pop_back();


	i = station.begin();
	i->choose = true;
	while( i != station.end())
	{
		j = i + 1;
		auto temp = station.end();
		for(;j != station.end() && j->distance <= i->distance+maxDist;++j)
		{
			//行程内站点Price低于当前站点,选择做为下一个加油站，当前站不加满
			if(j->price <= i->price)
			{
				i->full = false;
				j->choose = true;
				temp = j;
				//
				for(auto jj = i + 1; jj != j; ++jj)
					jj->choose = false;
				break;
			}
			//如果行程内站点price都大于当前站，选择price最小站点
			//且如果两站Price相同，选择较远的站
			if(temp == station.end())
			{
				temp = j;
				temp->choose = true;
			}
			else if(temp->price >= j->price)
			{
				temp->choose = false;
				j->choose = true;
				temp = j;
			}
		}
		i = temp;

	}

	//cal price
	vector<string> log;
	char str[120];

	double sumPrice = 0;
	double oil = 0;

	//station.push_back(s);
	i = station.begin();
	j = i + 1;
	for(; j != station.end();++j)
		if(j->choose == true)
		{
			if(i->full)//加满
			{
				double p = (cap-oil)*(i->price);
				//sprintf(str,"%d->%d : %.2f,full,%.2f->%.2f",i->distance,j->distance,p,oil,oil + p/i->price);
				//log.push_back(str);
				sumPrice += p;
				//到达j站时剩余油量
				oil = cap - (double)(j->distance - i->distance)/ave;
			}
			else//加到刚好能从i行驶到下一个要加油的站j
			{
				double oilNeed = (double)(j->distance - i->distance)/(double)ave;
				if(oil > oilNeed)//当前油量够，不用加油
				{
					oil -= oilNeed;
					//log.push_back("dont need!");
				}
				else
				{
					double p = ( oilNeed -oil )*i->price;
					//sprintf(str,"%d->%d : %.2f,%.2f->%.2f",i->distance,j->distance,p,oil,oil+p/i->price);
					//log.push_back(str);
					sumPrice += p;
					oil = 0;
				}
			}
			i = j;
		}

	//cout << endl;
	//for(auto i = station.begin(); i != station.end(); ++i)
	//{
	//	printf("%04d %d %.2f %d\n",i->distance,i->choose,i->price,i->full);
	//	//cout <<  " " << i->choose << " " << i->price << " " << i->full << endl;
	//}

	printf("%.2f",sumPrice);//不用四舍五入

	return 0;
}