

#include <iostream>
using namespace std;

bool binarySearch(int arr[],int s, int e, int key)
{
    // Base case
    if (s > e )
        return false;
    
    int mid = s + (e-s)/2;

    if(arr[mid] == key){
        return true;
    }

    else if(arr[mid] < key){
        binarySearch(arr, mid+1, e, key);
    }
    else{
        binarySearch(arr, s, mid-1 , key);
    }
}

int main()
{
    int arr[5] = {2, 3, 4, 5,6};
    int key=6;

    bool ans = binarySearch(arr , 0, 5, key  );

    if(ans){
        cout<<"Element is present"<<endl;
    }else{
        cout<<"Not present";
    }
}
