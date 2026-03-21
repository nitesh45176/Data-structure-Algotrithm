
// leetcode 110: Balanced Binary tree
// Approach: Recursion
// TC & SC: O(n) , O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 private:
    int height(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        
        return ans;
    }
public:
    pair<bool, int> isBalancedFast(TreeNode* root){
         // base case
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
             return p;
        }
        
        pair<int, int> left = isBalancedFast(root->left);
        pair<int, int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs( left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        ans.second = max(left.second , right.second) + 1;
        
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
    bool isBalanced(TreeNode* root) {
       return isBalancedFast(root).first;
    }
};
