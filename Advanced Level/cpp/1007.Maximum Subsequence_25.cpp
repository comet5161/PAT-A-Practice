#include<iostream>
#include<vector>


using namespace std;

int main()
{
	vector<int> v;
	int num;
	int a;

	cin >> num;

	for(int k = 0; k < num; ++k)
	{
		cin >> a;
		v.push_back(a);
	}

	int size = v.size();
	int sum = 0,this_sum = 0, this_sum_tmp = 0;
	int begin = 0 ,end = 0;
	int b = 0,e = 0;

	for(int k = 0; k < size; ++k) //全为负数时输出首尾两个数字 4 -1 -2 -3 -4 输出：0 -1 -4
	{
		if(v[k] >= 0) break;
		if( k == size - 1)
		{
			cout << 0 << " " << v[0] << " " << v[k];
			return 0;
		}
	}

	for(int k = 0 ; k < size; ++k)
	{
		this_sum += v[k];

		if(v[k] == 0 && sum == 0 && begin == 0)//4 -1 0 0 -5 输出: 0 0 0
			begin = end = k;

		if(this_sum < 0)
		{
			b = k + 1;
			this_sum = 0;
		}
		else if(this_sum > sum)
		{
			sum = this_sum;
			begin = b;
			end = k;
		}
		else if(sum == 0 )
		{

		}
	}

	cout << sum << " " << v[begin] << " " << v[end];

	return 0;
}

/*
5 -1 -2 0 0 -4 -5
0 -1 -1请按任意键继续. . .
*/