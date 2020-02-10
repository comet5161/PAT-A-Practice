#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    vector<long long> vPAT(n,0), vPA(n,0), vP(n,0); //vP[i]的值等于vP[0]~vP[i]间字符P的个数。
    if(str[0] == 'P')
        vP[0] = 1;
    for(int i = 1;  i < n; i++)
        if(str[i] == 'P')
            vP[i] = vP[i-1] + 1;
        else
            vP[i] = vP[i-1];
    for(int i = 1; i < n; i++)
    {
        if(str[i] == 'A')
            vPA[i] = vPA[i-1] + vP[i-1];
        else
            vPA[i] = vPA[i-1];
    }
    for(int i = 1; i < n; i++)
    {
        if(str[i] == 'T')
            vPAT[i] = vPAT[i-1] + vPA[i-1];
        else
            vPAT[i] = vPAT[i-1];
    }
    if(n > 0)
        cout << (vPAT[n-1] % 1000000007); //不取模，case 3和case 4通不过。
    else
        cout << 0;
    return 0;
}