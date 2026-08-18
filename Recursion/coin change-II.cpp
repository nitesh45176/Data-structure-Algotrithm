class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));

        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0] == 0) dp[0][amt] = 1;

            else dp[0][amt] = 0;
        }

        for(int i=1; i<n; i++){
            for(int amt=0; amt <= amount; amt++){
                long long notTake = dp[i-1][amt];

                long long take = 0;
                if(coins[i] <= amt){
                    take = dp[i][amt-coins[i]];
                }

                if(take > INT_MAX - notTake)
                    dp[i][amt] = INT_MAX;
                else
                    dp[i][amt] = take + notTake;
                    }
        }
        return dp[n-1][amount];
    }
};
