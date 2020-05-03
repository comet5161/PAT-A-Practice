//怎么确定是否有唯一的树， 其实就是看除了叶子以外的每个节点是否都有两个儿子， 因为有一个儿子的话，它既可以是左儿子也可以是右儿子。
#include <iostream>
#include <vector>

using namespace std;
vector<int> pos, pre, inOrder;

bool judge(int l1, int l2, int len){
    bool isUnique = true;
    int root = pre[l1];
    if(len < 1)
        return true;
    if(len == 1){ //root节点为叶节点
        inOrder.push_back(root);
    }
    else if( len == 2){ //root节点有1个子节点
        isUnique = false;
        inOrder.push_back(root); //假设子节点都为右子节点。
        inOrder.push_back(pre[l1+1]);
    }
    else{
        int len_left = 1;
        while(pos[l2 + len_left - 1] != pre[l1+1])
            len_left++;

        isUnique = isUnique && judge(l1 + 1, l2, len_left);
        inOrder.push_back(root);
        int len_right = len - 1 - len_left;
        if(len_right == 0)
            isUnique = false;
        isUnique = isUnique && judge(l1 + 1 +len_left, l2 + len_left, len_right);
    }
    return isUnique;
}
int main(){
    int n;
    cin >> n;
    pre.resize(n);
    pos.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &pos[i]);

    bool res = judge(0, 0, n);
    cout << ( res == true ? "Yes\n" : "No\n" );
    cout << inOrder[0];
    for(int i = 1; i < n; i++)
        printf(" %d", inOrder[i]);
    cout << endl;
    return 0;
}