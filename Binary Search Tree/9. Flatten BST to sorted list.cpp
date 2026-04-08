
//GeeksForGeek: Flatten BST to sorted list
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
    
    Node *flattenBST(Node *root) {
        vector<int> inorderVal;
        inorder(root, inorderVal);

        int n = inorderVal.size();
        if(n == 0) return NULL;

        Node* newRoot = new Node(inorderVal[0]);

        Node* curr = newRoot;

        for(int i=1; i<n; i++){
            Node* temp = new Node(inorderVal[i]);

            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }

        curr->left = NULL;
        curr->right = NULL;
        
        return newRoot;
    }
};

