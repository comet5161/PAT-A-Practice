#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > sequenceList;
vector<int> minSeq;
int n,m;


 vector<int>* Min( vector<int> *a,  vector<int> *b)
{
	auto i = a->begin();
	auto j = b->begin();
	for(;i != a->end() && j != b->end(); ++i,++j)
		if(*i < *j)
			return a;
		else if(*i > *j)
			return b;
	if(a->size() > b->size())
		return a;
	else
		return b;

};

void Find(int index,int sum,vector<int> &A, int seq[], int seq_id)
{
	//if(index >= n)
	//	return ;
	sum += A[index];
	seq[++seq_id] = A[index];
	if(sum == m)
	{
		vector<int> temp;
		for(int k = 0; k <= seq_id; ++k)
			temp.push_back(seq[k]);
		if(Min(&temp,&minSeq) != &minSeq)
			minSeq = temp;
		//sequenceList.push_back(temp);
	}
	else if(sum < m)
	{
		for(int k = index+1; k < n; ++k)
			Find(k,sum,A,seq,seq_id);
	}
};



struct SequenceCompare{
	bool operator () (const vector<int> &a, const vector<int> &b)
	{
		auto i = a.begin();
		auto j = b.begin();
		for(;i != a.end() && j != b.end(); ++i,++j)
			if(*i != *j)
				return *i < *j;
		return a.size() > b.size();
	}
};

int main()
{
	int seq[10000];
	cin >> n >> m;
	vector<int> A(n);
	for(int k = 0; k < n; ++k)
		scanf("%d",&A[k]);
	sort(A.begin(),A.end());
	vector<int> temp;
	for(int k = 0; k < n; ++k)
		Find(k,0,A,seq,-1);
	//sort(sequenceList.begin(),sequenceList.end(),SequenceCompare());

	if(minSeq.size() == 0)
		cout << "No Solution\n";
	else
	{
		//auto p = &*sequenceList.begin();
		//for(auto i = sequenceList.begin(); i != sequenceList.end(); ++i)
		//{
		//	p = Min(p,&*i);
		//}
		//auto &s = *p;
		auto &s = minSeq;
		for(auto i = s.begin(); i != s.end(); ++i)
		{
			if(i != s.begin())
				printf(" ");
			printf("%d",*i);
		}
		cout << endl;
	}
	return 0;
}