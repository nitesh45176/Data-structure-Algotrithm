


#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    // Base case
    if (n == 0 || n == 1) return ;

   for(int i=0; i<n ; i++){
     if(arr[i] > arr[i+1]){
        swap(arr[i], arr[i+1]);
     }
   }
  //recursive call
   BubbleSort(arr, n-1);
}

int main()
{
    int arr[5] = {5,1,7,2,5};

    BubbleSort(arr, 5);

    for(int i=0; i<5 ; i++){
        cout<< arr[i];
    }
}
