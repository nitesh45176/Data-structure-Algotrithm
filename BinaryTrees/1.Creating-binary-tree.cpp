
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int d){
      this->data = d;
      this->left = NULL;
      this->right = NULL;
    }
};
node* buildTree(node* root){
    cout<< "Enter the data: ";

    int data;
    cin>>data;
    
    if(data == -1){
        return NULL;
    }
    root = new node(data);
   
    cout<< "Enter data for inserting the left of "<<data<< endl;
    root->left = buildTree(root->left);
    
    cout<< "Enter data for inserting the right of "<<data<< endl;
    root->right = buildTree(root->right);

    return root;
}


int main(){
    node* root = NULL;

    root = buildTree(root);

}
