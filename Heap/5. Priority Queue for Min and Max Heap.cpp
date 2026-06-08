
#include <iostream>
#include<queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    };

    void deleteFromHeap(){

        // step-1:- swap root node with last node
        arr[1] = arr[size];

        // step-2:- remove last node
        size--;

        // step-3:- place the root node at correct position
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    } 

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[],int n ){
    int size = n;
    
    while(size > 1){
        swap(arr[size], arr[1]);    //step1
        size--;                //step2

        heapify(arr,size, 1);     //step3
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.deleteFromHeap();

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n=5;

    // heap creating
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    // heap sort
    heapSort(arr, n);
    cout<<" printing the array now"<<endl;
    for(int i=1; i<=n; i++){
        cout<< arr[i]<<" ";
    }
    cout<< endl;


    cout<<"Using priority Queue here"<<endl;
    // Max Heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(1);

    cout<<"element at Top"<< pq.top()<<endl;
    pq.pop();
    cout<< "element at top: ";

    cout<<"Size is: "<<pq.size();
    if(pq.empty()){
        cout<<"pq is empty";
    }
    else{
        cout<<"pq is not empty";
    }

    cout<<"Using priority Queue here for MIN HEAP"<<endl;
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(1);

    cout<<"element at Top"<< minheap.top()<<endl;
    minheap.pop();
    cout<< "element at top: "<<minheap.top()<<endl;

    cout<<"Size is: "<<minheap.size();
    if(minheap.empty()){
        cout<<"minheap is empty"<<endl;
    }
    else{
        cout<<"minheap is not empty"<<endl;
    }


}
