// 1090 Highest Price in Supply Chain (25point(s))
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//Case 3:只有root的情况。
using namespace std;

int GetDepth(vector<int>& v, vector<int>& depth, int id)
{
    int parent = v[id];
    if(parent == -1)
        depth[id] = 1;
    else if(depth[id] <= 0)
        depth[id] = 1 + GetDepth(v, depth, parent);
    return depth[id];
}

int main()
{
    int n;
    double price , rate;

    cin >> n >> price >> rate;
    vector<int> v(n), depth(n, -1);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    int max_depth = -1;
    for(int i = 0; i < n; i++)
    {
        if(depth[i] <= 0)
            GetDepth(v, depth, i);
        max_depth = max(depth[i], max_depth);
    }
    int cnt = count(depth.begin(), depth.end(), max_depth);
    double max_price = price * pow(1+rate/100.0, max_depth-1);
    printf("%.2f %d\n", max_price, cnt);
    
    return 0;
}