#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.rbegin(), v.rend());
    int end = 0;
    while( end < n && end + 1 < v[end])
        end++;
    cout << end << endl;
    return 0;
}