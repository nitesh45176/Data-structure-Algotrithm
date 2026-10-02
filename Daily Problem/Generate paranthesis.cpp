class Solution {
public:
    bool isValid(string current){
        int balance = 0;

        for(int i=0; i<current.size(); i++){
            if(current[i] == '(') balance++;

            else if(current[i] == ')') balance -- ;

            if(balance < 0) return false;
        }


        if(balance == 0) return true;

        return false;
    }
    void generate(string current, int n, vector<string>& ans){
        if(current.size() == 2*n){
            if(isValid(current)){
                ans.push_back(current);
            }
            return;
        }

        generate(current+"(", n, ans);

        generate(current+")", n, ans);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate("", n, ans);

        return ans;
    }
};
