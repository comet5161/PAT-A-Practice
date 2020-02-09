#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

int main()
{
	int n,x;
	map<int,int> num_count;
	vector<int> list;
	cin >> n;
	for(int k = 0; k < n; ++k)
	{
		scanf("%d",&x);
		num_count[x]++;
		list.push_back(x);
	}
	int res = -1;
	for(auto i = list.begin(); i != list.end(); ++i)
		if(num_count[*i] == 1)
		{
			res = *i;
			break;
		}
	if(res == -1)
		cout << "None\n";
	else
		cout << res << endl;

	return 0;
}