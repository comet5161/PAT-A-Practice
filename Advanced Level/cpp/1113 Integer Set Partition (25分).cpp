

//����һ��
//ʱ�临�Ӷȣ�nlog(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    cout << n % 2 << " " 
    << accumulate(v.begin()+n/2, v.end(), 0) 
	-    accumulate(v.begin(), v.begin()+n/2, 0);
    return 0;
}

//��������
//ʱ�临�Ӷȣ�O(n)
//���㣺���������е���λ��