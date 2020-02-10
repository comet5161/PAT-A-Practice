#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class  Record{
public:
    int seconds; //将一天中的时间用秒保存。
    bool status; //true = in, false = out
    friend bool operator < (const Record& r1, const Record& r2)
    {
        return r1.seconds < r2.seconds;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    map<string, vector<Record>> id_vRec;
    vector<int> vRealNum(3600*24+1, 0);
    vector<int> vInOut(3600*24+1,0);

    char c_id[10], c_status[4];
    int hour, minute, second;
    Record r;
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d %s", c_id, &hour, &minute, &second, c_status);
        r.status = false;
        if(string(c_status) == string("in"))
            r.status = true;
        r.seconds = hour*3600 + minute*60 + second;
        id_vRec[c_id].push_back(r);
    }

    vector<string> vMaxCars;
    int max_seconds = -1;
    for(auto iter = id_vRec.begin(); iter != id_vRec.end(); iter++)
    {
        string id = (*iter).first;
        auto& v = (*iter).second;
        sort(v.begin(), v.end());//将同一辆车的记录按时间排序。
        int second_sum = 0;
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i].status == false && v[i-1].status == true)
            {
                second_sum += v[i].seconds-v[i-1].seconds;
                vInOut[ v[i-1].seconds ]++;
                vInOut[ v[i].seconds ]--;
                i++;
            }
        }
        if(second_sum > max_seconds)
        {
            max_seconds = second_sum;
            vMaxCars.clear();
            vMaxCars.push_back(id);
        }
        else if( second_sum == max_seconds)
            vMaxCars.push_back(id);
    }

    vRealNum[0] = vInOut[0];
    for(int i = 1; i <= 3600*24; i++)
        vRealNum[i] = vRealNum[i-1] + vInOut[i];
    
    for(int i = 0; i < m; i++)
    {
        scanf("%d:%d:%d", &hour, &minute, &second);
        printf("%d\n", vRealNum[hour*3600+minute*60+second]);
    }

    for(int i = 0; i < vMaxCars.size(); i ++)
        cout << vMaxCars[i] << " ";
    printf("%02d:%02d:%02d", max_seconds/3600, (max_seconds%3600)/60, max_seconds%60);

    return 0;
}