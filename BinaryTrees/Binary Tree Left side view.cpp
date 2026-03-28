

// Leetcode 199: Binary Tree Left side view
// Approach : Recursion
// TC & SC : O(n) , O(n)

class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans, int level){
        if(root == NULL){
            return ;
        }
       // You entered in new level , push the first node element
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans , 0);
        return ans;
    }
};
