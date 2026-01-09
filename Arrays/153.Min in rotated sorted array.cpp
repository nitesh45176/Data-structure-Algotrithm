// LeetCode 153 : Find minimumin rotated sorteda array
// Approach: Binary search
// Time complexity : Best- O(nlogn), Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right = nums.size() -1;
        while(left < right){
            int mid = left + (right - left)/2;

            if(nums[mid] <= nums[right]){
                right = mid;
            }
            else{
                left = mid +1;
            }
        }
        return nums[left];
    }
};

