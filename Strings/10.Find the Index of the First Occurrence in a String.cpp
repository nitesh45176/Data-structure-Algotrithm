
// Leetcode 28 : Find the Index of the First Occurrence in a String
// TC, SC:   O(n) , O(1)


class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = haystack.find(needle);
        if(pos != string::npos){
            return pos;
        }
        return -1;
    }
};
