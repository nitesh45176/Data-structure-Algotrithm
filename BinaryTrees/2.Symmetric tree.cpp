
//leetcode 101: Symmetric tree
// Approach: recursion
// TC & SC: O(n) & O(n)

class Solution {
private:
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL){
            return true;
        }
        if(left==NULL || right==NULL){
            return false;
        }
        if(left->val != right->val){
            return false;
        }

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        //base case
        if(root == NULL){
            return true;
        }

        return isMirror(root->left, root->right);
    }
};
