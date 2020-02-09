#include <iostream>
#include <iomanip>
#include <list>

#define INIFINT 999999999;

using namespace std;
typedef struct Rode{
    int distance;
    int city;
} RodeInf;
typedef struct City{
    int capacity;
    int min_dist;
    bool known;
    int *path;
    list<RodeInf> rodes;
} CityInf;


CityInf C[500];
int N,M,sorce_city,dest_city;
int path_num = 1;

int FindMinDist();


int* IntAdd(int *p, int v)
{
    int n = p[0]+ 1;
    int* s = new int(n+1);
    if(p != NULL)
        for(int k = 1; k <= n; ++k)
            s[k] = p[k];
    s[0] = p[0];
    s[n] = v;
    delete [] p;
    return s;
}

void GetPathNum(int city)
{
    if(city == sorce_city)
        return ;
    if( C[city].path[0] >0)
        path_num += C[city].path[0] - 1;
    for(int k = 1; k <= C[city].path[0]; ++k)
        GetPathNum(C[city].path[k]);
}

int GetCapacity(int city)
{
    if(city == sorce_city)
        return C[sorce_city].capacity;
    int temp = 0;
    int max = 0;
    //cout << " GetCap: " << city << endl;
    for( int k = 1; k <= C[city].path[0]; ++k )
    {
        int c = C[city].path[k];
        temp = C[city].capacity + GetCapacity(c);
        if(temp > max)
            max = temp;
    }
    return max;
}


int main()
{


    int k, a, b, l;
    int i;
    int dist;
    RodeInf *pRode;
    cin >> N >> M >> sorce_city >> dest_city;
    k=-1;

    while(++k<N)
    {
        cin >> C[k].capacity;
        C[k].known = false;
        C[k].min_dist = INIFINT;
        C[k].path = new int(0);
    }
    k=-1;
    while(++k<M){
        cin >> a >> b >> l;
        pRode = new RodeInf;
        pRode->city = b;
        pRode->distance = l;
        C[a].rodes.push_back(*pRode);
        delete [] pRode;
        pRode = new RodeInf;
        pRode->city = a;
        pRode->distance = l;
        C[b].rodes.push_back(*pRode);
        delete [] pRode;
    }

    C[sorce_city].known = true;
    C[sorce_city].min_dist = 0;
    int index = sorce_city;
    //Dijkstra
    while(1)
    {

        //printf("=>%d\n",index);
        if(index == -1)
            break;
        CityInf &city = C[index];
        city.known = true;
        //iter = city.rodes.begin();
        for(auto iter:city.rodes)
        {
            int d1 = iter.distance;
            int d2 = city.min_dist;
            if( C[iter.city].min_dist >= iter.distance+city.min_dist )
            {
                C[iter.city].min_dist = iter.distance+city.min_dist;
                C[iter.city].path = IntAdd( C[iter.city].path , index);
                C[iter.city].path[0] += 1;
            }
        }
        if( index == dest_city)
            break;
        index = FindMinDist();
    }


    GetPathNum(dest_city);
    cout << path_num << " " << GetCapacity(dest_city);





    return 0;
}

int FindMinDist()
{
    int k, min_dist=INIFINT;
    int index = -1;

    for(k=0; k<N; ++k)
    {
        if(C[k].known == true)
        {
            if(C[k].rodes.empty())
                continue;

            for(auto iter:C[k].rodes)
            {
                if( C[iter.city].known == false )
                    if( C[iter.city].min_dist <= min_dist)
                    {
                        min_dist = C[iter.city].min_dist;
                        index = iter.city;
                    }
            }
        }

    }
    return index;
}




