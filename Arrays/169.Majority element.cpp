// LeetCode 169 :Majority element
// Approach: sorting
// Time complexity : Best- O(nlogn), Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};
