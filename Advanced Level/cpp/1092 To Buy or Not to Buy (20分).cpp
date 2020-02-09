//1092 To Buy or Not to Buy (20分)
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    string offer, need;
    int missing = 0;
    vector<int> cnt(128,0);
    getline(cin, offer);
    getline(cin, need);
    for(auto i : offer)
        cnt[i]++;
    for(auto i : need)
        if(--cnt[i] < 0)
            missing++;
    if(missing == 0)
        cout << "Yes " << offer.size()-need.size();  
    else
        cout << "No " << missing;
    return 0;
}