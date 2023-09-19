#include <iostream>
using namespace std;

bool linear_search(int *arr, int size,int data)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == data)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int *arr = new int[10];
    for(int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    if(linear_search(arr,10,11))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}