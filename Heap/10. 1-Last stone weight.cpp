
// Leetcode 1046 : Last stone weight
// Approach : Brute force solution uing sorting
// TC, SC :-  o(n * nlogn) , o(n)


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size() > 1){
            sort(stones.begin(), stones.end());

            int a = stones.back();
            stones.pop_back();

            int b = stones.back();
            stones.pop_back();

            stones.push_back(abs(a-b));


        }
        return stones[0];
    }
};
