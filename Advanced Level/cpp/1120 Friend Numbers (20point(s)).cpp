#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x;
    set<int> res;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        res.insert(sum);
    }
    cout << res.size() << endl;
    for(auto iter : res){
        if(iter != *res.begin())
            cout << " ";
        cout << iter;
    }
    cout << endl;
    return 0;
}