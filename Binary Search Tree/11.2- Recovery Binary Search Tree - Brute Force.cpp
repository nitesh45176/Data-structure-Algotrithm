

// Leetcode 99:  Recover Binary Search Tree
//Approach : Recursive
// TC & SC : O(nlogn) , O(n)


class Solution {

public:
    void inorderStore(TreeNode* root, vector<int> inorderVal){
        if(root==NULL) return;

        inorderStore(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorderStore(root->right, inorderVal);

    }

    void inorderFix(TreeNode* root, vector<int> &inorderVal, int &i){
        if(root==NULL) return;

        inorderFix(root->left, inorderVal, i);
        root->val = inorderVal[i++];
        inorderFix(root->right, inorderVal, i);

    }
    void recoverTree(TreeNode* root) {
       
        vector<int> inorderVal;

        inorderStore(root, inorderVal);
        
        sort(inorderVal.begin(), inorderVal.end());
        
        int i=0;
        inorderFix(root, inorderVal, i);
    }
};
