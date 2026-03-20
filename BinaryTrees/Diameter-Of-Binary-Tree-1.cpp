
// Leetcode 543: Diameter of Binary Tree
// Approach: Recursion
// TC & SC : O(n*n) , O(n)


class Solution {
private:
    int height(Node* node) {
        if(node == NULL){
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);

        return max(left, right) + 1;
    }

public:
    int diameter(Node* root) {
        if(root == NULL){
            return 0;
        }

        int op1 = diameter(root->left);
        int op2 = diameter(root->right);

        int op3 = height(root->left) + height(root->right); // FIXED

        return max(op1, max(op2, op3));
    }
};
