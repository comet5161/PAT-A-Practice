// 坑：注意只有左节点和右节点的情况
// BST的mirror tree就是递减二叉排序树。

#include<iostream>
#include<vector>
using namespace std;

vector<int> vPostOrder; // true表示递增排序，false表示递减排序
bool orderFlag;
bool visit(vector<int>& v, int begin, int end)
{
    int n = end - begin + 1;
    if(n == 0)
        return true;
    int x = v[begin];
    if(n == 1)
        vPostOrder.push_back(x);
    else // size >= 2
    {
        int i = begin+1;
        while(i <= end && (v[i] < x == orderFlag)) // 若v[i]与v[i-1]同样都小于x或大于等于x
            i++;
        int j = i;
        while(j <= end)
            if(v[j++] >= x != orderFlag)
                return false;

        if( visit(v, begin+1, i-1) == false )
            return false;
        if(i <= end && visit(v, i, end) == false )
            return false;
        vPostOrder.push_back(x);
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    if(n > 1)
        orderFlag = v[1] < v[0];
    if( visit(v, 0, n-1) )
    {
        cout << "YES\n" << vPostOrder[0];
        for(int i = 1; i < n; i++)
            cout << " " << vPostOrder[i];
    }
    else
        cout << "NO";
    
    return 0;
}