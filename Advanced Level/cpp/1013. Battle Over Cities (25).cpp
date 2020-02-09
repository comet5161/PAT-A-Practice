#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<set>
#include<queue>

using namespace std;

class City
{
public:
	int id;
	vector<int> c;//连接的城市
};

int root[1001];

int Check(map<int,City*>& C,int unlink);

int main()
{
	int N,M,K;
	map<int,City*> citys,temp;
	
	cin >> N >> M >> K;
	for(int k = 1; k <= N; ++k)
	{
		citys[k] = new City;
		citys[k]->id = k;
	}
	for(int k = 0; k < M; ++k)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		citys[a]->c.push_back(b);
		citys[b]->c.push_back(a);
	}

	for(int k = 0; k < K; ++k)
	{
		int unlinked;
		cin >> unlinked;
		temp = citys;
		temp.erase(unlinked);
		cout << Check(temp,unlinked) << endl;
	}
	return 0;
}

int Check(map<int,City*>& C,int unlink)
{
	vector<int> cityList;
	
	map<int,bool> found;
	int ret = -1;
	found[unlink] = true;
	int num = C.size() + 1;
	for(int k = 1; k < num; ++k)
		root[k] = -1;

	while(!C.empty())
	{
		queue<int> cQueue;
		cQueue.push(C.begin()->first);
		found[C.begin()->first] = true;
		while(!cQueue.empty())
		{
			int key = cQueue.front();
			cityList = C[key]->c;
			//for each connected to key
			for(auto i = cityList.begin(); i != cityList.end(); ++i)
				if(found[*i] == false)
				{
					cQueue.push(*i);
					found[*i] = true;
				}
			cQueue.pop();
			C.erase(key);
		}
		++ret;
	}
	return ret;
}