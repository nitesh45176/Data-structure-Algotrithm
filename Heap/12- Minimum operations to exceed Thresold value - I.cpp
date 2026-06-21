// Leetcode 2530 : Minimum operations to exceed Thresold value - I
// Approach :- Heap
// TC, SC :- O(n), O(n)


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < k){
                count++;
            }
        }
        return count;
    }
};
