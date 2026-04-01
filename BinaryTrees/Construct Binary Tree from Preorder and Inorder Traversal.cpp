
// leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal
// Approach: Recursion
// TC & SC: O(n) , O(n)


class Solution {
public:
    int findPosition(vector<int>& inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element){
                return i;
            }
        }
            return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd,  int n){
        // Base case
        if( index >= n || inorderStart > inorderEnd){
            return NULL;
        }

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);

        root->left = solve(preorder, inorder, index, inorderStart, position-1, n );
        root->right = solve(preorder, inorder, index, position+1, inorderEnd, n );

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex =0;
        int n = inorder.size();
        TreeNode* ans = solve(preorder, inorder, preorderIndex, 0, n-1, n);
        return ans;
    }
};
