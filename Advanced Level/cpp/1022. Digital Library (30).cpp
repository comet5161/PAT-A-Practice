#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

int main()
{
	int m,n,k,id;
	char str[101];
	string title,author,keyword,publisher,year;
	multimap<string,long> title_id,author_id,keyword_id,publisher_id,year_id, *mapList[5];
	mapList[0] = &title_id;
	mapList[1] = &author_id;
	mapList[2] = &keyword_id;
	mapList[3] = &publisher_id;
	mapList[4] = &year_id;

	cin >> n;
	for(k = 0; k < n; ++k)
	{
		scanf("%ld\n",&id);// \n²»ÄÜÉÙ£¡
		cin.getline(str,100);
		title = str;
		cin.getline(str,100);
		author = str;
		cin.getline(str,100);
		keyword = str;
		cin.getline(str,100);
		publisher = str;
		cin >> year;
		title_id.insert( make_pair(title,id) );
		author_id.insert( make_pair(author,id) );
		keyword.push_back(' ');
		string ky;
		for(auto i = keyword.begin(); i != keyword.end(); ++i)
			if(*i == ' ')
			{
				keyword_id.insert( make_pair(ky,id));
				ky.clear();
			}
			else
				ky.push_back(*i);
		publisher_id.insert( make_pair(publisher,id));
		year_id.insert( make_pair(year,id));
	}
	//get search queries
	cin >> m;
	int type;
	string q;
	vector<pair<int,string>> list;
	for(k = 0; k < m; ++k)
	{
		scanf("%d: ",&type);
		cin.getline(str,100);
		q = str;
		list.push_back( make_pair(type,q) );
	}

	//print result
	set<int> idSet;
	for(auto i = list.begin(); i != list.end(); ++i)
	{
		cout << i->first << ": " << i->second <<  endl;
		multimap<string,long> *p = mapList[i->first - 1];
		auto lower = p->lower_bound(i->second);
		auto upper = p->upper_bound(i->second);
		if(lower == upper)
		{
			cout << "Not Found" << endl;
			continue;
		}
		idSet.clear();
		for(auto i = lower; i != upper; ++i)
			idSet.insert(i->second);
		for(auto i = idSet.begin(); i != idSet.end(); ++ i)
			printf("%07d\n",*i);
	}
	return 0;
}