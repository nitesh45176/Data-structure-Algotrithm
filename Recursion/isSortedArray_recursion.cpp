

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{

    // Base case
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool ans = isSorted(arr + 1, size - 1);
        return ans;
    }
}

int main()
{
    int arr[4] = {2, 3, 4, 5};

    int ans = isSorted(arr, 4);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }else{
        cout<<"Not sorted";
    }
}
