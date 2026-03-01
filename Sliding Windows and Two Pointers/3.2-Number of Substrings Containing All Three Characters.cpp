

// Leetcode 1358 : Number of Substrings Containing All Three Characters
// Approach : Hashing
// TC and SC : O(n) and O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        int lastSeen[3] ={-1, -1, -1};

        for(int i=0; i<n; i++){
            lastSeen[s[i]-'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1  && lastSeen[2] != -1){
                count = count + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
            }
        }
        return count;
    }
};
