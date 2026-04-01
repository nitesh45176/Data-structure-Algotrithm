

// leetcode 106: Construct Binary Tree from Postorder and Inorder Traversal
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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd,  int n){
        // Base case
        if( index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);

        root->right = solve(postorder, inorder, index, position+1, inorderEnd, n );
        root->left = solve(postorder, inorder, index, inorderStart, position-1, n );

        return root;
    }
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
        int n = inorder.size();
        int postorderIndex = n-1;
        TreeNode* ans = solve(postorder, inorder, postorderIndex, 0, n-1, n);
        return ans;
    }
};
