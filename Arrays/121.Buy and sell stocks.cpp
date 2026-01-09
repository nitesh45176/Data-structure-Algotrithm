// LeetCode 121 : Best time to buy and sell stock
// Approach: Two pointers
// Time complexity : Best- O(n), Space: O(n)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxProfit = 0;
        int minProfit = INT_MAX;
        

        for(int i=0 ; i<n ; i++){
            if(prices[i] < minProfit){
                minProfit = prices[i] ;
            }

            int profit = prices[i] - minProfit;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
        
};
