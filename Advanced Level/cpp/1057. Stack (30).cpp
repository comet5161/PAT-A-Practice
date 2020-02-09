//用两个map实现

#include<iostream>
#include<sstream>
#include<set>
#include<string>
#include<vector>

using namespace std;

// 使 b.size+1 >= a.size >= b.size
void Balance(multiset<int> &a, multiset<int> &b)
{
	while(a.size() < b.size())
	{
		a.insert(*b.begin());
		b.erase(b.begin());
	}
	while(a.size() - b.size() > 1)
	{
		b.insert(*a.rbegin());
		a.erase(--a.end());
	}
};

int main()
{
	multiset<int> bigger,smaller;
	int mid;
	vector<int> stack;
	stringstream scout;
	char c[20];
	string str;
	int n,x;
	cin >> n;
	for(int k = 0; k < n; ++k)
	{
		scanf("%s",c);
		str = c;
		if(str == "Pop")
		{
			if(stack.size() == 0)
				scout << "Invalid\n";
			else
			{
				x = *stack.rbegin();//栈顶元素
				scout << x << endl;
				if( x <= *smaller.rbegin())
					smaller.erase(smaller.lower_bound(x));
				else 
					bigger.erase(bigger.lower_bound(x));
				Balance(smaller,bigger);
				stack.pop_back();
				if(stack.size() > 0)
					mid = *smaller.rbegin();
			}
		}
		else if(str == "Push")
		{
			scanf("%d",&x);
			//初始为空
			if(stack.size() == 0)
				smaller.insert(x);
			else if( x <= *smaller.rbegin())
				smaller.insert(x);
			else 
				bigger.insert(x);
			Balance(smaller,bigger);
			stack.push_back(x);
			mid = *smaller.rbegin();
		}
		else//PeekMedian
		{
			if(stack.size() > 0)
				scout << mid << endl;
			else
				scout << "Invalid\n";
		}
	}

	cout << scout.str();
	return 0;
}