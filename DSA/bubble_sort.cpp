#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> v)
{
    int len = v.size();
    for(int i = 0;i < len - 1; len--)
    {
        for(int j = i; j < len - 1; j++)
        {
            if(v[j] > v[j + 1])
            {
                swap(v[j],v[j + 1]);
            }
        }
    }
    return v;
}

int main()
{
    vector<int> v = {2,8,5,7,0,1,4,6,9,3};
    v = bubble_sort(v);
    cout << "Sorted array:" << endl;
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}