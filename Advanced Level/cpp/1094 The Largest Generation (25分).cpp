#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> Children;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Children> v(n+1);

    for(int i = 0; i < m; i++)
    {
        int id_p, id_c, k;
        cin >> id_p >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> id_c;
            v[id_p].push_back(id_c);
        }
    }

    //广度优先搜索。
    vector<int> gen_cur, gen_next;
    int max_level = 1, max_num = 0;
    gen_cur.push_back(1);

    int level = 0;
    while(gen_cur.size() > 0)
    {
        ++level;
        if(max_num < gen_cur.size())
        {
            max_level = level;
            max_num = gen_cur.size();
        }
        gen_next.clear();
        for(auto i : gen_cur)
            gen_next.insert(gen_next.end(), v[i].begin(), v[i].end());
        gen_cur = gen_next;
    }
    cout << max_num << " " << max_level;
    return 0;
}