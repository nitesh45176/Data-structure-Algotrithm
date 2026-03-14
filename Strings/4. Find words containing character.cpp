
// Leetcode 2942:  Find words containing character
// Approach : Traversing
// TC, SC :   O(n) , O(n)


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0; i<words.size(); i++){
            if(words[i].find(x) != string::npos){
                ans.push_back(i);
            }
        }
        return ans;
    }
}
