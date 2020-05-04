/*
哈密顿回路。由指定的起点前往指定的终点，途中经过所有其他节点且只经过一次。
在图论中是指含有哈密顿回路的图，闭合的哈密顿路径称作哈密顿回路，含有图中所有顶点的路径称作哈密顿路径。
*/
//坑case 1：

//图比较小，用邻接矩阵速度比邻接表速度更快。
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
#else
    //freopen("1.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int n, edgeNum;
    cin >> n >> edgeNum;
    bool graph[204][204];//邻接表
    fill(graph[0], graph[0] + 204*204, false);
    int v1, v2;
    for(int i = 0; i < edgeNum; i++){
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }
    int queryNum, v;
    cin >> queryNum;
    for(int i = 0; i < queryNum; i++){
        int num;
        cin >> num;
        set<int> mySet;
        vector<int> vPath(num);
        for(int j = 0; j < num; j++){
            scanf("%d", &v);
            mySet.insert(v);
            vPath[j] = v;
        }
        bool flag = true;
        if(mySet.size() == n && num == n + 1 && vPath[0] == vPath[num-1]){
            for(int j = 1; j < num; j++){ //这里写成j < n 的话case 1 通不过。
                int curr = vPath[j-1];
                int next = vPath[j];
                if(graph[curr][next] == false){
                    flag = false;
                    break;
                }
            }
        }
        else{
            flag = false;
        }
        printf(flag ?  "YES\n" : "NO\n");
    }
    
    return 0;
}