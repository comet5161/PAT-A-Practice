/*
�����Ŀ�տ�ʼ���ò��鼯������������ʵ��ͨ�ģ���Ϊ�п����ǻ�����ȷ����һ��ͼ��

�����Ŀ��һ�뷨Ӧ������DFS������BFSҲ�У�������DFSϰ���ˡ�

////�ò��鼯���Ե�3�δ���
//�ҵ����Ե�3�δ����ԭ���ˣ���Ϊ�����������ֶ���һ��������MAX > 2000 ������ 1000

http://www.cnblogs.com/championlai/p/4086003.html

//���鼯����Ҳ������
http://www.cnblogs.com/huhuuu/p/3357332.html
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<tuple>


#define MAX 2009
using namespace std;

class Record {
public:
	string s1,s2;
	int w;//weight
	Record(string s1,string s2,int w):s1(s1),s2(s2),w(w){}
};

int root[MAX];
int weight[MAX];
int groupWeight[MAX];
int groupSize[MAX];

int FindRoot(int x)
{
	if(root[x] == x)
		return x;
	return FindRoot(root[x]);
}

void Union(int a, int b)
{
	int r1 = FindRoot(a);
	int r2 = FindRoot(b);
	if(r1 == r2) return;//˵�����ڵ��Ѵ���ͬһ�����£����������κβ������Է��л���ͼ���³���
	root[r2] = r1;
}

int main()
{
	int N,K;
	string s1,s2;
	int w;
	set<string>name;
	map<string,int> name_id;
	map<int,string> id_name;

	vector<Record> record;

	cin >> N >> K;

	for(int k = 0; k < N; ++k)
	{
		cin >> s1 >> s2 >> w;
		name.insert(s1);
		name.insert(s2);
		Record r1(s1,s2,w);
		record.push_back(r1);
	}

	//assign id to names
	int idx = -1;
	int size = name.size();
	for(auto i = name.begin(); i != name.end();++i)
	{
		name_id[*i] = ++idx;
		id_name[idx] = *i;
	}

	//find and union
	for(int k = 0; k < size; ++k)
	{
		root[k] = k;
		weight[k] = 0;
		groupWeight[k] = 0;
		groupSize[k] = 0;
	}
	for(auto i = record.begin(); i != record.end(); ++i)
	{
		int id1 = name_id[i->s1];
		int id2 = name_id[i->s2];
		weight[id1] += i->w;
		weight[id2] += i->w;
		Union(id1,id2);
	}
	for(int k = 0; k < size; ++k)
		root[k] = FindRoot(k);

	//find gangs
	vector<int> group_root;
	map<int,pair<int,int>> gang;//root of gang,head of gang,gang size
	for(int k = 0; k < size; ++k)
	{
		int r = root[k];
		groupWeight[r] += weight[k];
	}
	for(int k = 0; k < size; ++k)
		if(groupWeight[k]/2 > K)
		{
			gang[k].first = k;//head
			gang[k].second = 0;
		}

	//find gang head
	for(int k = 0; k < size; ++k)
	{
		int r = root[k];
		if(gang.find(r) == gang.end())
			continue;
		int head = gang[r].first;
		if(weight[head] < weight[k])
			gang[r].first = k;
		++gang[r].second;//size++
	}
	map<string,int> head_size;
	for(auto i = gang.begin(); i != gang.end(); ++i)
	{
		int id = i->second.first;//head
		int size = i->second.second;//size
		if(size > 2)
			head_size[id_name[id]] = size;
	}

	cout << head_size.size() << endl;
	for(auto i = head_size.begin(); i != head_size.end(); ++i)
		cout << i->first << " " << i->second << endl;

	return 0;
}