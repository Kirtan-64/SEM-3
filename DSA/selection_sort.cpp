#include <iostream>
#include <vector>
using namespace std;

vector<int> selection_sort(vector<int> v)
{
    int len = v.size();
    for(int i = 0; i < len; i++)
    {
        int tmp = i;
        for(int j = i + 1; j < len; j++)
        {
            if(v[j] < v[tmp])
            {
                tmp = j;
            }
        }
        swap(v[i],v[tmp]);
    }
    return v;
}

int main()
{
    vector<int> v = {2,8,5,7,0,1,4,6,9,3};
    v = selection_sort(v);
    cout << "Sorted array:" << endl;
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}