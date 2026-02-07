
// Leetcode 339 : Find the Difference
// Approach : Two pointers
// TC, SC:   O(n) , O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sn = s.length();
        int ln = t.length();
        int s1=0;

        for(int i=0; i<sn; i++){
            s1+= s[i];
        }
        int s2=0;
        for(int i=0; i<ln; i++){
            s2+= t[i];
        }
        return s2-s1;
    }
};
