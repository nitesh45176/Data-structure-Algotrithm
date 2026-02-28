// Leetcode 3 :  Longest Substring Without Repeating Characters
// Approach : Sliding window
// TC and SC : O(n) and O(256)


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l, r = 0;
        int maxLen = 0;
        int hash[256];

        for (int i = 0; i < 256; i++) {

            hash[i] = -1;
        }
        while (r < n) {
            
            // if repeating character is in window update l
            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
            
            // update r
            hash[s[r]] = r;

            int len = r - l + 1;
            maxLen = max(maxLen, len);
            r++;
        }

        return maxLen;
    }
};
