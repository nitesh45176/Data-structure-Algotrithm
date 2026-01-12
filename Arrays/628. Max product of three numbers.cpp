// LeetCode 628 : Max product of three numbers
// Approach: sorting
// Time complexity : Best- O(nlogn), Space: O(1)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();

        // Case 1: product of 3 largest numbers
        int p1 = nums[n-1] * nums[n-2] * nums[n-3];

        // Case 2: product of 2 smallest (possibly negative) and the largest
        int p2 = nums[0] * nums[1] * nums[n-1];

        return max(p1, p2);
    }
};
