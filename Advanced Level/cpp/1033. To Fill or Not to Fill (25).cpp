/*

���⣺

��S��Dһ·��N������վ���ͼ۸��죩��������ʡǮ�ļ��Ͳ��ԡ�

������

̰�Ĳ��ԣ����������Լ�����Aվ��Ҫ���ǵ���AվҪ��Ҫ���ͣ��Ӷ����͵����⡣�ҵ���ǰ�ɴﷶΧ�ڣ�����Aվcmax*davg����һ��Ҫ���͵�վB��
Aվ�ɴﷶΧ�ڣ� �����������

��û�м���վ��------- �쵽�յ��ˣ���������͵��յ㣻���� Impossible����Aվ�����͵������ģ�

���и����˵ļ���վ ------- ���ҵ���һ�ұ�A���˵ļ���վB���Ӿ������ٵ��ͣ�Ҳ�����͹�ֱ�ӿ���ȥ����Bվ��

��ֻ�м۸���ߵļ���վ��------����Aվ�����ͣ�Ѱ���������˵ļ���վB ����ȥ��



żȻ������Ĵ��룬��֮ǰҲ�ǲ��Ե�4û��ͨ��������AC�ˣ����õĲ������ݣ�
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
��ȷ����767.50
�Ҵ����ԭ���ǵ����ڶ�������վ6.00 1250��ʱ����Ӧ��ֱ�ӿ����յ㣬
������ȴ������6.85 1280�ĵط��ٵ��յ㣬�ҵ������ǰ����һ������վ��Ϊprice = 0��distance = D��
�������ԭ����Ҳ�һ���ɣ�ϣ��������AC��Best Wishes to you~
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
	bool choose;//�Ƿ��ڸ�վ����
	bool full;//�Ƿ����
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
			//�г���վ��Price���ڵ�ǰվ��,ѡ����Ϊ��һ������վ����ǰվ������
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
			//����г���վ��price�����ڵ�ǰվ��ѡ��price��Сվ��
			//�������վPrice��ͬ��ѡ���Զ��վ
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
			if(i->full)//����
			{
				double p = (cap-oil)*(i->price);
				//sprintf(str,"%d->%d : %.2f,full,%.2f->%.2f",i->distance,j->distance,p,oil,oil + p/i->price);
				//log.push_back(str);
				sumPrice += p;
				//����jվʱʣ������
				oil = cap - (double)(j->distance - i->distance)/ave;
			}
			else//�ӵ��պ��ܴ�i��ʻ����һ��Ҫ���͵�վj
			{
				double oilNeed = (double)(j->distance - i->distance)/(double)ave;
				if(oil > oilNeed)//��ǰ�����������ü���
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

	printf("%.2f",sumPrice);//������������

	return 0;
}