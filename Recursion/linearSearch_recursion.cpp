

#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{

    // Base case
    if (size == 0 )
        return false;

    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        bool remainingPart = linearSearch(arr + 1, size - 1, key);
        return remainingPart;
    }
}

int main()
{
    int arr[4] = {2, 3, 4, 5};
    int key=4;

    bool ans = linearSearch(arr, 4, key );

    if(ans){
        cout<<"Element is present"<<endl;
    }else{
        cout<<"Not present";
    }
}
