//1091 Acute Stroke (30分)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> VV;

int M, N, L, T;

//广度优先搜索
struct Pos{
    int x, y, z;
};
int BreadthVisit(vector<VV>&v, int x, int y, int z)
{
    if(v[x][y][z] == 0)
        return 0;
    queue<Pos> que;
    int cnt = 0;
	Pos pos = {x,y,z};
    que.push(pos);
    v[x][y][z] = 0;
    while(que.size() > 0)
    {
        Pos& pos = que.front();
        x = pos.x;
        y = pos.y;
        z = pos.z;
        que.pop();
        cnt++;
        if(x > 0 && v[x - 1][y][z] == 1)
        {
            v[x - 1][y][z] = 0;
			Pos pos = {x-1,y,z};
            que.push(pos);
        }
        if(y > 0 && v[x][y-1][z] == 1)
        {
            v[x][y-1][z] = 0;
			Pos pos = {x,y-1,z};
            que.push(pos);
        }
        if(z > 0 && v[x][y][z-1] == 1)
        {
            v[x][y][z-1] = 0;
			Pos pos = {x,y,z-1};
            que.push(pos);
        }
        if(x < L-1 && v[x+1][y][z] == 1)
        {
            v[x+1][y][z] = 0;
			Pos pos = {x+1,y,z};
            que.push(pos);
        }
        if(y < M-1 && v[x][y+1][z] == 1)
        {
            v[x][y+1][z] = 0;
			Pos pos = {x,y+1,z};
            que.push(pos);

        }
        if(z < N-1 && v[x][y][z+1] == 1)
        {
            v[x][y][z+1] = 0;
			Pos pos = {x,y,z+1};
            que.push(pos);
        }
    }
    return cnt;
}

//深度优先搜索
//Case4和5会出现段错误，应该时递归栈溢出了。
int Visit(vector<VV>& v, int x, int y, int z)
{
    int cnt = 0;
    if(v[x][y][z] == 1)
    {
        cnt++;
        v[x][y][z] = 0;
        if(x > 0)
            cnt += Visit(v, x - 1, y, z);
        if(y > 0)
            cnt += Visit(v, x, y - 1, z);
        if(z > 0)
            cnt += Visit(v, x, y, z - 1);
        if(x < L-1)
            cnt += Visit(v, x + 1, y, z);
        if(y < M-1)
            cnt += Visit(v, x, y + 1, z);
        if(z < N-1)
            cnt += Visit(v, x, y, z + 1);
    }
    return cnt;
}

int main()
{
    cin >> M >> N >> L >> T;
    VV e(M,vector<char>(N,0));
    vector<VV> v(L, e);
    for(int i = 0; i < L; i++)
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < N; k++)
                scanf("%d", &v[i][j][k]);
        }
    
    int blockCnt = 0;
    for(int i = 0; i < L; i++)
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < N; k++)
            {
				int block = BreadthVisit(v, i, j, k);
                if(block >= T)
                    blockCnt += block;
            }
        }

    cout << blockCnt;
    return 0;
}