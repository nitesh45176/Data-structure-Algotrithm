// LeetCode 53 : Maximum subarray
// Approach: Kadane's algorithm
// Time complexity : Best- O(n), Space: O(1)


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        

        if (sum > maxi) {
            maxi = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
        }
        return maxi;
    }
};
