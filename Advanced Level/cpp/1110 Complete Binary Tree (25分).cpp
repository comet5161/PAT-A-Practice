// cpp_hello.cpp : 定义控制台应用程序的入口点。
//

#include <stdafx.h>

int main();
int _tmain(int argc, _TCHAR* argv[])
{
	char c;
	main();
	return 0;
}




#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> l(n, -1),r(n, -1), hasParent(n, -1);
    string s1, s2;
    for(int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if(s1 != "-")
        {
            l[i] = stoi(s1);
            hasParent[l[i]] = i;
        }
        if(s2 != "-")
        {
            r[i] = stoi(s2);
            hasParent[r[i]] = i;
        }
    }
    // find root
    int root = -1;
    for(int i = 0; i < n; i++)
        if(hasParent[i] == -1)
            root = i;
    
    // judge
    bool isCompleteTree = true, hasChildren = true;
    int lastNode;
    vector<int> queue, next;
    queue.push_back(root);
    while(queue.size() > 0)
    {
        next.clear();
        for(int i = 0; i < queue.size(); i++)
        {
            int x = queue[i];
            lastNode = x;
            if(l[x] >= 0)
			{
                next.push_back(l[x]);
				if(hasChildren == false)
					isCompleteTree = false;
			}
            else
				hasChildren = false;
            if(r[x] >= 0)
			{
                next.push_back(r[x]);
				if(hasChildren == false)
					isCompleteTree = false;
			}
            else
				hasChildren = false;
        }
        queue = next;
    }
    if(isCompleteTree)
        cout << "YES " << lastNode;
    else
        cout << "NO " << root;
    return 0;
}