#include<iostream>

using namespace std;

int main()
{
	int num;
	int sum = 0;
	int last = 0;
	int next;
	cin >> num;
	for(int k = 0; k < num ; ++k)
	{
		cin >> next;
		if(next - last > 0)
		{
			sum += (next - last) * 6 + 5;
		}
		else
		{
			sum += (last - next) * 4 + 5;
		}
		last = next;
	}

	cout << sum;
	return 0;
}