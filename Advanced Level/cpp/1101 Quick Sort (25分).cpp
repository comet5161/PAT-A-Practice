// 测试点2坑！个数为0时，输出一个换行符，不能忽略！
// 符合条件的数：在其最终位置，左边的比它小，右边的比它大。
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n), v2;
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    v2 = v;
    sort(v2.begin(), v2.end());
    vector<int> res;
    int max_prev = v[0];
    if(v[0] == v2[0])
        res.push_back(v[0]);
    for(int i = 1; i < n; i++)
    {
        max_prev = max(max_prev, v[i]);
        if(v2[i] == v[i])
        {
            int x = v[i];
            if(max_prev == v[i])
                res.push_back(v[i]);
        }
    }
    
    cout << res.size() << endl;
    if(res.size() > 0)
    {
        cout << res[0];
        for(int i = 1; i < res.size(); i++)
        printf(" %d", res[i]);
    }
    cout << "\n";
    return 0;
}