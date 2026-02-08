
// Leetcode 520 : Detect capital
// Approach : Two pointers
// TC, SC:   O(n) , O(1)


class Solution {
public:
    bool detectCapitalUse(string word) {
        
           bool allUpper = true;
           bool allLower = true;
           bool firstUpper = true;

           for(int i=0; i<word.length(); i++){
              if(!isupper(word[i])){
                allUpper = false;
              }
              if(!islower(word[i])){
                allLower = false;
              }
              if(i==0){
                 if(!isupper(word[i])){
                    firstUpper = false;
                 }
              }else{
                if(!islower(word[i]))
                firstUpper = false;
              }
           }
return allUpper || allLower || firstUpper;

    }
};
