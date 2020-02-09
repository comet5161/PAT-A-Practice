#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class People{
public:
	int id;
	int type;//0-3 sages,nobleman,fooman,small man
	int virtue;
	int talent;
	int sum;
	friend bool operator < (const People &a, const People &b)
	{
		if(a.type != b.type)
			return a.type < b.type;
		if(a.sum != b.sum)
			return a.sum > b.sum;
		if(a.virtue != b.virtue)
			return a.virtue > b.virtue;
		return a.id < b.id;
	}
};

int main()
{
	int n,high,low,id,virtue,talent;
	cin >> n >> low >> high;
	vector<People> x;
	for(int k = 0; k < n; ++k)
	{
		People p;
		scanf("%d %d %d",&id,&virtue,&talent);
		if( virtue < low || talent < low)
			continue;
		p.id = id;
		p.sum = virtue + talent;
		p.talent = talent;
		p.virtue = virtue;
		if(talent >= high && virtue >= high)
			p.type = 0;
		else if( talent < high && virtue >= high)
			p.type = 1;
		else if( talent <= virtue && virtue < high)
			p.type = 2;
		else
			p.type = 3;
		x.push_back(p);
	}

	sort(x.begin(),x.end());
	cout << x.size() << endl;
	for(auto i = x.begin(); i != x.end(); ++i)
		printf("%08d %d %d\n",i->id,i->virtue,i->talent);
	return 0;
}