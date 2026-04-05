
//Leetcode 230 :Kth Smallest element in BST
//Approach : Recursive
// TC & SC : O(n) , O(n)

class Solution {
public:
    int solve(TreeNode* root,  int &i, int k){
        if(root==NULL){
            return -1;
        }

        //L
       int left = solve(root->left, i, k);

        if(left != -1){
            return left;
        }

        //N
        i++;
        if(i == k){
            return root->val;
        }

        //r
        int right = solve(root->right, i, k);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans = solve(root, i, k);
        return ans;
    }
};
