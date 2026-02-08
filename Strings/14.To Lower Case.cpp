

// Leetcode 709 : To Lower Case
// Approach : Traversing
// TC, SC:   O(n) , O(1)


class Solution {
public:
    string toLowerCase(string s) {
       for(int i=0; i<s.length(); i++){
         if(s[i]>= 'A' && s[i]<='Z'){
            s[i]+= 32;
         }
       }
return s;
    }
};
