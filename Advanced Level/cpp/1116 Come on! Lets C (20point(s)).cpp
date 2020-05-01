#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

bool IsPrime(int x){
    if( x == 2 || x == 3)
        return true;
    int n = sqrt(x) + 1;
    for(int i = 2; i <= n; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n, id, k;
    cin >> n;
    map<int, int> idToRank;
    for(int i = 0; i < n; i++){
        cin >> id;
        idToRank[id] = i+1;
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> id;
        printf("%04d: ",id);
        if(idToRank.find(id) != idToRank.end()){
            int rank = idToRank[id];
            if(rank < 0)
                printf("Checked\n");
            else if(rank == 1)
                printf("Mystery Award\n");
            else if(IsPrime(rank))
                printf("Minion\n");
            else 
                printf("Chocolate\n");
            idToRank[id] = -1;
        }
        else
            printf("Are you kidding?\n");
    }
    return 0;
}