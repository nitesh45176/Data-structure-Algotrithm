
// Geeks for Geeks  : Height of Binary Tree
// Approach: Recursion
// TC & SC: O(n), O(n)


#include <algorithm>
using namespace std;

class Solution{
public:
      int height(struct Node* node) {
    // base case
    if(node == NULL){
        return -1;
    }
    int left = height(node->left);
    int right = height(node->right);
    
    int ans = max(left, right) + 1;
    
    return ans;
    
}
};
