#include <iostream>
using namespace std;
template <typename T> 

struct Node{
  T data;
  Node* left, right;
};


template <typename T> 

Node* getNewNode(T data){
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}
template <typename T> 

void Insert(Node** root, T data){
  if(*root == NULL){
      *root = getNewNode(data);
  }else if(data<= *root->data){
    *root->left = Insert(*root->left,data);
  }else if(data>=*root->data){
    *root->right = Insert(*root->right,data);
  }
}
template <typename T>
void remove(const T &t){

}
template <typename T> 
int main(){
  Node *root = NULL;
  Insert(root, 3);
  Insert(root,5);
  return 0;
}