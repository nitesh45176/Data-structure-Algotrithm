
// Leetcode  42 : Trapping Rain water
// Approach : By calculating leftMac==x and rightMax
// Tc and SC: O(n)  ,  S(n)


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int total = 0;

        //leftSum
        prefix[0] = height[0];
        for(int i=1; i<n; i++){
           prefix[i] = max(prefix[i-1], height[i]);
        }

        //rightSum
        suffix[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
           suffix[i] = max(suffix[i+1], height[i]);
        }


        for(int i=0; i<height.size(); i++){
            int leftMax = prefix[i];
            int rightMax = suffix[i];
            if(height[i] < leftMax && height[i] < rightMax){
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};
