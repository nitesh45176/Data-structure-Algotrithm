## Geeks for Geeks



class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        
        // step 1
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        
        //step 2
        for(int i=k; i<arr.size(); i++){
            if(arr[i] <  pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        // step 3
        int ans = pq.top();
        return ans;
    }
};
