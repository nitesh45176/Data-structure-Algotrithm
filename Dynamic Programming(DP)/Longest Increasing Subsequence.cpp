class Solution {
public:
    int f(int i, int previ, vector<int>& nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;

        if(dp[i][previ+1] != -1) return dp[i][previ+1];

        int len = 0 + f(i+1, previ, nums, dp);

        if(previ == -1 || nums[previ] < nums[i]){
            len = max(len, 1+f(i+1, i, nums, dp));
        }

        return dp[i][previ+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};
