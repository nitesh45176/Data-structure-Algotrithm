// LeetCode 34 :   Find the first and last element of sorted array
// Approach: Binary search
// Time complexity : Best- O(n), Space: O(n)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int ans1 = -1;

        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                ans1 = mid;
                end = mid-1;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        start=0;
        end = nums.size()-1;
        int ans2 = -1;

         while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                ans2 = mid;
                start = mid+1;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return {ans1, ans2};
    }
};
