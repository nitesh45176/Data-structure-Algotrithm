


// Leetcode 387 :   Find unique character in string
// Approach :  Stack
//  Tc and SC :  O(n)  ,  O(1)


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);

        for(char c: s){
            freq[c-'a']++;
        }

        for(int i=0; i<s.length(); i++){
            if(freq[s[i] - 'a'] == 1){
            return i;
        }
        }
        return -1;
    }
};
