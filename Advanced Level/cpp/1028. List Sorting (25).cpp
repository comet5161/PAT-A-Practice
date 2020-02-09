#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Record{
public:
	static int sortColumn;
	int id,grade;
	string name;
	Record(int id,string name,int grade):id(id),grade(grade),name(name){}
	friend bool operator < (const Record& a, const Record& b)
	{
		int c = a.sortColumn;
		if( c == 2)
			if(a.name != b.name)
				return a.name < b.name;
		if(c == 3)
			if(a.grade != b.grade)
				return a.grade < b.grade;
		return a.id < b.id;
	}
};

int Record::sortColumn = 1;

int main()
{
	vector<Record> list;
	string name;
	int id,grade;
	char str[30];

	int n,c;
	cin >> n >> c;
	for(int k = 0; k < n; ++k)
	{
		scanf("%d%s%d",&id,str,&grade);
		name = str;
		Record r(id,name,grade);
		list.push_back(r);
	}

	Record::sortColumn = c;
	sort(list.begin(),list.end());
	for(auto i = list.begin(); i != list.end(); ++i)
	{
		printf("%06d ",i->id);
		cout << i->name;
		printf(" %d\n",i->grade);
	}

	return 0;
}