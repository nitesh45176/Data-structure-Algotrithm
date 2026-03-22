
// leetcode 110: Sum Binary tree
// Approach: Recursion
// TC & SC: O(n) , O(n)


class Solution {
  public:
    pair<bool, int> isSumTreeFast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        //Avoid leaf nodes
        if(root->left == NULL && root->right == NULL){
     return make_pair(true, root->data);
}
        
        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool condn = root->data == leftAns.second + rightAns.second;
        
        pair<bool, int> ans;
        
        if(left && right && condn){
            ans.first = true;
            ans.second = root->data + leftAns.second + rightAns.second;
        }
        else{
            ans.first = false;
            ans.second = 0;
        }
        return ans;
    }
    bool isSumTree(Node* root) {
        
        return isSumTreeFast(root).first;
        
    }
};
