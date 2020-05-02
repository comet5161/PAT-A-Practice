// 考点：并查集
// 坑：不压缩路径，case 3 会超时。
// 另一种描述：给出某个亲戚关系图，求家族数量和判断任意给出的两个人是否具有亲戚关系。
#include <iostream>
#define MAX_SIZE 10005
using namespace std;

int root[MAX_SIZE];
int depth[MAX_SIZE];

void init(){
    for(int i = 0; i < MAX_SIZE; i++){
        root[i] = i;
        depth[i] = 1;
    }
}

int find(int x){
    if( x == root[x])
        return x;
    int r = find(root[x]);
    root[x] = r; //压缩路径
    return r;
}

void merge(int i, int j){
    int r1 = find(i);
    int r2 = find(j);
    //将深度浅的合并到深的树中。
    if(depth[r1] == depth[r2]){
        depth[r1] ++;
        root[r2] = r1;
    }
    else if(depth[r1] > depth[r2])
        root[r2] = r1;
    else
        root[r1] = r2;
}

int main(){
    int n, k, birdNum, bird1, bird2;
    birdNum = 0;
    cin >> n;
    init();
    for(int i = 0; i < n; i++){
        scanf("%d %d", &k, &bird1);
        birdNum = max(birdNum, bird1);
        for(int j = 1; j < k; j++){
            scanf("%d", &bird2);
            merge(bird1, bird2);
            birdNum = max(birdNum, bird2);
        }
    }
    int treeNum = 0; 
    for(int i = 1; i <= birdNum; i++)
        if(root[i] == i)
            treeNum++;
    cout << treeNum << " " << birdNum << endl;
    int query;
    cin >> query;
    for(int i = 0; i < query; i++){
        scanf("%d %d", &bird1, &bird2);
        if(find(bird1) == find(bird2))
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}