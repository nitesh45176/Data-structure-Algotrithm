
// Leetcode 930 : Binary Subarrays With Sum
// Approach : Slidig window
// TC and SC : O(n) and O(1)

class Solution {
public:
    int Most(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int count=0;
        int sum=0;
        int l=0;
        int r=0;

        while(r < n){
            sum = sum + nums[r];

            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
        count = count + (r-l+1);
        r++;
    }
    return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return Most(nums,goal) - Most(nums, goal-1);
    }
};
