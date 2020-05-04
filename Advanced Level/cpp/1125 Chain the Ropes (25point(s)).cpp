// 先选短的，再选长的。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& iter: v)
        cin >> iter;
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++){
        v[i] = (v[i-1] + v[i]) / 2;
    }
    cout << v[n-1];
    return 0;
}

