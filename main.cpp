#include <iostream>
using namespace std;


struct BstNode{
  int data;
  BstNode* left;
  BstNode* right;
};



class BST{
  BstNode *root = NULL;
public:
BstNode* getNewNode(int data){
  BstNode* newNode = new BstNode();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}
BstNode* insert(int data){
  if(root==NULL){
    root = getNewNode(data);

  }else if(root->data >=data){
    root->left= insert(root->left,data);

  }else{
    root->right = insert(root->right,data);
  }
    return root;
}
};




BstNode* remove(const int &t){
  
}

int main(){
  BstNode *root = NULL;
  root=insert(root, 15);
  root=insert(root, 10);
  root=insert(root, 20);
}
