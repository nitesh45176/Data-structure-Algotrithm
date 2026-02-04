
// Leetcode 1903 : Largest Odd number
// Approach : skipping even number and printing largest odd no
// TC, SC:   O(n) , O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.length()-1;

        while(i>=0 && (num[i]-'0') % 2 ==0){
            i--;
        }
        
        if( i<0){
            return "";
        }
        return num.substr(0, i+1);
    }
};
