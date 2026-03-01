
// Leetcode 1358 : Number of Substrings Containing All Three Characters
// Approach : Hashing
// TC and SC : O(n*n) and O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i=0; i<n ; i++){
           int hash[3] = {0};
            for(int j=i; j<n; j++){
                // mark it as visited
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    count++;
                }
            }
        }
        return count;
    }
};
