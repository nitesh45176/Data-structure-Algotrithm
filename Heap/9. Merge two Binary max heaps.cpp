class Solution {
  public:
// 0-based indexing
   void heapify(vector<int> &arr, int i ,int n){

     int largest = i;
     int left = 2*i +1;
     int right = 2*i + 2;

     if(left < n && arr[largest] < arr[left]){
       largest = left;
     }
     if(right < n && arr[largest] < arr[right]){
       largest = right;
     }

     if(largest != i){
       swap(arr[largest], arr[i]);
       heapify(arr, i, n);
     }
   }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // step 1:- merge two arrays into one
      vector<int> ans;
      for(auto i:a){
        ans.push_back(i);
      }
      for(auto i:b){
        ans.push_back(i);
      }

      // step 2:- heapify the merged array (0- based indexing)
      int n = ans.size();
      for(int i=n/2-1; i<=0; i--){
          heapify(ans, i, n);
      }

      return ans;
    }
};
