
//GeeksForGeek:  NormalBST to BalancedBST
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
    
    Node* inorderBST(int s, int e, vector<int> &in){
        if(s>e) return NULL;
        
        int mid =(s+e)/2;
        Node* root = new Node(in[mid]);
        root->left = inorderBST(s, mid-1, in);
        root->right = inorderBST(mid+1, e, in);
        
        return root;
    }
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> inorderVal;
        
        inorder(root, inorderVal);
        
        return inorderBST(0, inorderVal.size()-1, inorderVal);
    }
};
