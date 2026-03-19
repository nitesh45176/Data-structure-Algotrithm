

#include<iostream>
#include<queue>
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

void levelOrderTraversal(node* root){
    queue<node*> q;
    
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
       node* temp = q.front();
       
       q.pop();

       if(temp == NULL){   // purana level compelete ho chuka hai
          cout<< endl;
          if(!q.empty()){
            q.push(NULL);
          }
       }
       else{
          cout<< temp->data << " ";
          if(temp->left){
            q.push(temp->left);
          }
          if(temp->right){
            q.push(temp->right);
          }
       }
    }

}


int main(){
    node* root = NULL;

    root = buildTree(root);

    cout<<"Printing the level order traversal"<<endl;

    levelOrderTraversal(root);

}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
