//1097 Deduplication on a Linked List (25分)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
void Print(vector<int>& v, vector<int>& vKey);
int main()
{
    int n, head, key, addr, next;
    cin >> head >> n;
    vector<int> vNext(1000*1000+1, -1);
    vector<int> vKey(1000*1000+1, -1);
    vector<bool> vHas(10000+1,false);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &addr, &key, &next);
        vNext[addr] = next;
        vKey[addr] = key;
    }
    int i = head;
    vector<int> vRemain, vRemove;
    while(i != -1)
    {
        key = abs(vKey[i]);
        if(vHas[key] == false)
        {
            vRemain.push_back(i);
            vHas[key] = true;
        }
        else
            vRemove.push_back(i);
        i = vNext[i];
    }
    Print(vRemain, vKey);
    Print(vRemove, vKey);
    return 0;
}

void Print(vector<int>& v, vector<int>& vKey)
{
    int addr, key, next;
    int n = v.size();
    if(n > 0)
    {
        for(int i = 0; i < n-1; i++)
        {
            addr = v[i];
            key = vKey[addr];
            next = v[i+1];
            printf("%05d %d %05d\n", addr, key, next);
        }
        addr =v[n-1];
        key = vKey[addr];
        printf("%05d %d -1\n", addr, key);
    }
}