#  Leetocde 215: Kth Largest element
# Approach : Heap
# TC & SC :- O(n logk) ,    O(k)


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // step 1
        for(int i=0; i<k; i++){
            pq.push(nums[i]);

        }
        
        //step 2
        for(int i=k; i<nums.size(); i++){
            if(nums[i] >  pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        // step 3
        int ans = pq.top();
        return ans;
    }
};
