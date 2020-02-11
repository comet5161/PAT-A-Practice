// 1098 Insertion or Heap Sort (25分)
//本题堆排序实际上只需实现AdjustDown,不必实现完整的堆排序
//堆排序用的是大根堆，不是小根堆，每次遍历将大根与其最终位置的元素交换，堆大小减一，然后调整堆，直到堆大小<=1。
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void AdjustDown(vector<int>& v,int parent, int n)
{
    int x = v[parent];
    int child = parent*2+1;
    while(child < n)//有子节点
    {
        if(child + 1 < n && v[child] < v[child+1]) child++; //右子节点
        if(x < v[child])//注意，是x 不是v[parent].
        //if(v[parent] < v[child])
        {
            v[parent] = v[child];
            //swap(v[parent], v[child]);
            parent = child;
            child = parent*2+1;
        }
        else break;
    }
    v[parent] = x;
}

//建大根堆
void BuildHeap(vector<int>& v)
{
    int n = v.size();
    for(int i = (n-1)/2; i >= 0; i--)
        AdjustDown(v, i, n);
}
bool IsHeapSort(vector<int>& vSrc, vector<int>& vMid)
{
    vector<int> v = vSrc;
    int n = v.size();
    BuildHeap(v);
    for(int i = n-1; i > 0; i--)
    {
        swap(v[0], v[i]);
        AdjustDown(v, 0, i);
        if(v == vMid)
        {
            --i;
            swap(vMid[0], vMid[i]);
            if(i > 0)
                AdjustDown(vMid, 0, i);
            return true;
        }
    }
    return false;
}

bool IsInsertSort(vector<int>& vSrc, vector<int>& vMid)
{
    int n = vSrc.size();
    int i = 1;
    while(i < n && vMid[i-1] <= vMid[i]) i++;
	int pos = i;
    for(; i < n; i++)
        if(vMid[i] != vSrc[i])
            return false;
    sort(vMid.begin(), vMid.begin()+pos+1);
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vSrc(n,0);
    vector<int> vMid(n,0);
    for(int i = 0; i < n; i++)
        cin >> vSrc[i];
    for(int i = 0; i < n; i++)
        cin >> vMid[i];

    if(IsInsertSort(vSrc, vMid))
        cout << "Insertion Sort" << endl;
    else if(IsHeapSort(vSrc, vMid))
        cout << "Heap Sort" << endl;
    
    string strout;
    for(int i = 0; i < vMid.size(); i++)
        strout += to_string(vMid[i]) + " ";
    strout.pop_back();
    cout << strout;

    
    return 0;
}