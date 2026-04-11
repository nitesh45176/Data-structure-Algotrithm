
// Leetcode 99:  Recover Binary Search Tree
//Approach : Inorder traversal
// TC & SC : O(n) , O(1)


class Solution {
private:
  TreeNode* first;
  TreeNode* prev;
  TreeNode* middle;
  TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;

        inorder(root->left);

        if(prev != NULL && root->val < prev->val){
            // Cheeck if its first violation 
            // if it is then mark first and middle
            if(first==NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }

    prev = root;
    inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = NULL;
        last = NULL;middle = NULL;prev = NULL;

        prev = new TreeNode(INT_MIN);

        inorder(root);

        if(first && last){
            return swap(first->val, last->val);
        }
        else if(first && middle){
            return swap(first->val, middle->val);
        }

    }
};
