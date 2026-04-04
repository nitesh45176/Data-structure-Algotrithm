
// Leetcode 700: Search in BST
// Approach: Iteraive


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;

        while(temp != NULL){
            if(temp->val == val){
                return temp;
            }
            if(temp->val < val){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        return NULL;
    }
};
