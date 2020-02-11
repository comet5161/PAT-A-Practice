// 1099 Build A Binary Search Tree (30分)
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node{
    int data, left, right;
};

void InOrderSearch(vector<Node>& vNode, vector<int>& vSeq, int idx)
{
    int left = vNode[idx].left;
    int right = vNode[idx].right;
    if(left > 0)
        InOrderSearch(vNode, vSeq, left);
    vSeq.push_back(idx);
    if(right > 0)
        InOrderSearch(vNode, vSeq, right);
}

void BreadthFirstSearch(vector<Node>& vNode, vector<int>& vSeq)
{
    queue<int> que;
    vSeq.clear();
    que.push(0);
    while(que.size() > 0)
    {
        int idx = que.front();
        int left = vNode[idx].left;
        int right = vNode[idx].right;
        que.pop();
        vSeq.push_back(idx);
        if(left > 0) que.push(left);
        if(right > 0) que.push(right);
    }
}

int main()
{
    int n, left, right, data;
    cin >> n;
    vector<Node> vNode(n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &vNode[i].left, &vNode[i].right);
    
    vector<int> vData(n);
    for(int i = 0; i < n; i++)
        cin >> vData[i];
    sort(vData.begin(), vData.end());
    vector<int> vSeq;
    InOrderSearch(vNode, vSeq, 0);
    for(int i = 0; i < vSeq.size(); i++)
        vNode[vSeq[i]].data = vData[i];
    
    BreadthFirstSearch(vNode, vSeq);
    cout << vNode[ vSeq[0] ].data;
    for(int i = 1; i < vSeq.size(); i++)
        cout << " " << vNode[ vSeq[i] ].data;
    return 0;
}