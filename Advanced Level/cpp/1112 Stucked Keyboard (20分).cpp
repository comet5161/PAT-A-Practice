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
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int k;
    cin >> k;
    string str;
    cin >> str;

    str.push_back('#');
    int len = str.size();
    vector<bool> isStucked(128, true);

    int cnt = 1;
    for(int i = 1; i < len; i++){
        if(str[i] == str[i-1])
            cnt++;
        else{
            if(cnt % k != 0)
                isStucked[str[i-1]] = false;
            cnt = 1;
        }
    }
    string res;
    set<char> setStucked;
    for(int i = 0; i < len - 1;){
        char c = str[i];
        res.push_back(c);
        if(isStucked[c] == true){
            i += k;
            if(setStucked.find(c) == setStucked.end())
                cout << c;
            setStucked.insert(c);
        }
        else
            i += 1;
    }

    cout << endl << res;

    return 0;
}