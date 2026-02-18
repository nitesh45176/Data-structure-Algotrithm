
// Leetcode 503 :   Next Greater Element II
// Approach :  monotonic Stack
//  Tc and SC :  O(n*n)  ,  O(1)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, -1);

        for(int i=0; i<n; i++){
            for(int j=i+1; j< n+i ; j++){
                int index = j%n;

                if(nums[index]> nums[i]){
                    arr[i] = nums[index];
                    break;
                }
            }
        }
        return arr;
    }
};
