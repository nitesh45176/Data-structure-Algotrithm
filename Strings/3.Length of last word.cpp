
// Leetcode 58: Length of last word
// Approach : 
// TC, SC:   O(n) , O(1)


class Solution {
public:
    
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        
        // Removing trailing spaces
        while(i>=0 && s[i] ==' '){
            i--;
        }
        
        // calculating length of last word
        int length = 0;
        while(i >= 0 && s[i] != ' '){
            length++;
            i--;
        }
        return length;
    }
};
