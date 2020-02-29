
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Node{
public:
    int id,left, right;
    Node(){left = -1; right = -1;}
};

void InOrder(vector<Node>& vTree, vector<Node>& out, int root)
{
    if(root >= 0)
    {
        InOrder(vTree, out, vTree[root].right);
        out.push_back(vTree[root]);
        InOrder(vTree, out, vTree[root].left);
    }
};

void Print(vector<Node>& v)
{
    if(v.size() > 0)
    {
        cout << v[0].id;
        for(int i = 1; i < v.size(); i++)
            cout << " " << v[i].id;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<Node> v(n);
    char l,r;
    vector<bool> hasParent(n, false);
    for(int i = 0; i < n; i++)
    {
        v[i].id = i;
        cin >> l >> r;
        if(l != '-')
        {
            v[i].left = l - '0';
            hasParent[l - '0'] = true;
        }
        if(r != '-')
        {
            v[i].right = r - '0';
            hasParent[r-'0'] = true;
        }
    }
    int root = 0;
    for(int i = 0; i < n; i++)
        if(hasParent[i] == false)
            root = i;
    vector<Node> inOrder, levelOrder;
    //in order
    InOrder(v, inOrder, root);
    //level order
    vector<Node> queue;
    queue.push_back(v[root]);
    while(queue.size()>0)
    {
        vector<Node> next_level;
        for(int i = 0; i < queue.size(); i++)
        {
            levelOrder.push_back(queue[i]);
            if(queue[i].right >= 0)
                next_level.push_back( v[queue[i].right] );
            if(queue[i].left >= 0)
                next_level.push_back( v[queue[i].left] );
        }
        queue = next_level;
    }
    
    Print(levelOrder);
	Print(inOrder);

    return 0;
}