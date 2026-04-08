

//GeeksForGeek:Kth Smallest element in BST
//Approach : Recursive
// TC & SC : O(n) , O(n)



class Solution {
  public:
    void inorder(Node *root, vector<int> &in){
        if(root==NULL) return;
        
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    bool findTarget(Node *root, int target) {
        vector<int> inorderVal;
        inorder(root, inorderVal);
        
        int i=0, j=inorderVal.size()-1;
        
        while(i<j){
           int sum = inorderVal[i] + inorderVal[j];
           
           if(sum == target){
               return true;
           }
           else if(sum < target){
               i++;
           }
           else{
               j--;
           }
        }
        return false;
    }
};
