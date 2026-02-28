
// Leetcode 3 :  Longest Substring Without Repeating Characters
// Approach : Hashing
// TC and SC : O(n*n) and O(256)


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        int maxLen =0;
        for(int i=0 ; i<n; i++){
           int hash[256] = {0};
            for(int j=i; j<n; j++){
                if(hash[s[j]] == 1) break;

                int len = j-i+1;
                maxLen = max(maxLen, len);

                hash[s[j]] = 1; // mark it as visited
            }
        }
        return maxLen;
    }
};
