
// Leetcode 14 :  Longest Common Prefix
// Approach : Sorting
// TC, SC:   O(n) , O(1)


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string ans = "";

        string first = strs[0];
        string end = strs[n-1];

        for(int i=0; i< min(first.size(), end.size()); i++){
            if(first[i] != end[i]){
                return ans;
            }
            ans += first[i];
        }
    return ans;
    }
};
