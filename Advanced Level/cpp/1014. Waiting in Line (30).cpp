//注意条件是要在17:00之前(不包括17:00)serve的都可以，比如说某顾客从16:00-18:00结束，那么输出结果为18:00而不是Sorry。 
//注意大小写！Sorry 不要写成sorry!
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class Custom{
public:
	int id;
	int q;//require time
	int doneTime;
	Custom(int id,int q): doneTime(999999+17*60), id(id), q(q){}
};

class Window{
public:
	queue<Custom*> custom;
	int totalTime;
	Window(): totalTime(8*60){}
};

int main()
{
	int N,M,K,Q;
	int k;
	vector<Window> win;
	vector<Custom> cus;

	cin >> N >> M >> K >> Q;
	int qTime;
	//customers and requires
	for(k = 0; k < K; ++k)
	{
		scanf("%d",&qTime);
		cus.push_back( *(new Custom(k,qTime)) );
	}
	//windows
	for(k = 0; k < N; ++k)
		win.push_back( *(new Window()));

	int index = 0;
	int done = 0;
	int time = 8*60-2;
	while(done < K)
	{
		++time;
		//pop
		for(auto iter = win.begin(); iter != win.end(); ++iter)
			if(iter->custom.size() > 0 && time >= iter->custom.front()->doneTime)
			{
				iter->custom.pop();
				++done;
			}
		//push
		for(int num = 0; num < M; ++num)
			for(auto iter = win.begin(); iter != win.end(); ++iter)
				if(iter->custom.size() == num && index < K)
				{
					iter->totalTime += cus[index].q;
					cus[index].doneTime = iter->totalTime;
					iter->custom.push(&cus[index++]);
				}
	}
	//quire
	int *qList = new int[Q];
	for(k = 0; k < Q; ++k)
		cin >> qList[k];
	//print
	for(k = 0; k < Q; ++k)
	{
		int dt = cus[ qList[k]-1 ].doneTime;
		int st = dt - cus[ qList[k]-1 ].q;
		if(st >= 17 * 60)
			cout << "Sorry" << endl;
		else
			printf("%02d:%02d\n",dt/60,dt%60);
	}
	return 0;
}

