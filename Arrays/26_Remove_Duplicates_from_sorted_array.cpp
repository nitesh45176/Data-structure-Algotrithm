// LeetCode 26: Remove Duplicates from Sorted Array
// Approach: Two Pointers
// Time: O(n), Space: O(1)



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int k=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
