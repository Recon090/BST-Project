#include <iostream>
using namespace std;

struct BstNode{
  int data;
  BstNode* left;
  BstNode* right;
};


BstNode* getNewNode(int data){
  BstNode* newNode = new BstNode();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Function to perform in-order traversal
void inOrderTraversal(BstNode* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);   // Visit left subtree
        std::cout << node->data << " "; // Visit node
        inOrderTraversal(node->right);  // Visit right subtree
    }
}

BstNode* insert(BstNode* root, int data){
  if(root==NULL){
    root = getNewNode(data);

  }else if(root->data >=data){
    root->left= insert(root->left,data);

  }else{
    root->right = insert(root->right,data);
  }
    return root;
}

void remove(BstNode** root, const int &t){
  if((*root)->data==t){
    if((*root)->left==NULL && (*root)->left==NULL){
      
    }
  }else{
  try{
    if((*root)->left==NULL && (*root)->left==NULL){
      throw 1;
    }
  }
  catch(int x){
    cout<<"\nException thrown, BinarySearchTreeNodeNotFound exiting program";
    exit(1);
  }

  if((*root)->data>=t){
    BstNode** leftPtr = &((*root)->left);
    remove(leftPtr,t);

  }else{
    BstNode** rightPtr = &((*root)->right);
    remove(rightPtr,t);
  }
  }
  
}

int main(){
  BstNode *root = NULL;
  BstNode **rootPtr = &root;
  root=insert(root, 15);
    root=insert(root, 12);
      root=insert(root, 13);
        root=insert(root, 14);
          root=insert(root, 16);
            root=insert(root, 17);
              root=insert(root, 18);
  inOrderTraversal(root);
  remove(rootPtr,4);
  cout<<"Finished";
  return 0;
}
