//坑:只要连续的序列的乘积被n整除就行，不需要factor[1]*factor[2]*...*factor[k]*k == n。
#include <iostream>
#include <cmath>
using namespace std;
typedef long long Num;
int main()
{
    Num n;
    cin >> n;
    Num begin;
    Num max_len = 0;
	Num maxn = sqrt(n)+1;
    for(Num i = 2; i <= maxn; i++)
    {
        Num j = i ;
        Num mul = i;
        while(n % mul == 0)
        {
            mul *= ++j;
            if(max_len < j-i)
            {
                max_len = j-i;
                begin = i;
            }
        }
    }
    if(max_len > 0)
    {
        cout << max_len << endl;
        cout << begin;
        for(int k = 1; k < max_len; k++)
            cout << "*" << k+begin;
    }
    else
        cout << 1 << endl << n;
    return 0;
}