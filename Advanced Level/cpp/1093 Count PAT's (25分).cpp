#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    vector<long long> vPAT(n,0), vPA(n,0), vP(n,0); //vP[i]��ֵ����vP[0]~vP[i]���ַ�P�ĸ�����
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
        cout << (vPAT[n-1] % 1000000007); //��ȡģ��case 3��case 4ͨ������
    else
        cout << 0;
    return 0;
}