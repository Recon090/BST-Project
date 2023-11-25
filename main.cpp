#include <iostream>
using namespace std;

template<typename T>
class BinarySearchTree {
private:
struct BstNode{
    T data;
    BstNode *left, *right, *parent;

    BstNode(T value, BstNode *left = NULL, BstNode *right = NULL, BstNode *parent = NULL) {
        this->data = value;
        this->left = left;
        this->right = right;
        this->parent = parent;
    }
};
BstNode* minValueNode(BstNode* node) {
        while (node && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    BstNode *root;

    BstNode* insert(BstNode* node, T data) {
        if (node == NULL) {
            return new BstNode(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void inOrderTraversal(BstNode* node) const {
        if (node != NULL) {
            inOrderTraversal(node->left);
            cout << " " << node->data;
            inOrderTraversal(node->right);
        }
    }
    void remove(const T &t){
      BstNode *node= root;
      BstNode *temp;
      BstNode *parent = NULL;

      while(node!=NULL && node->data!=t){
        parent = node;
        if(node->data>=t){
          node = node->left;
        }else{
          node = node->right;
        }
      }
    try{
      if(node==NULL){
      throw 1;
      }
    }
    catch(int x){
     cout<<"\nException thrown, BinarySearchTreeNodeNotFound exiting program";
      exit(1);
    }

     if (node->left != NULL && node->right != NULL) {
            BstNode *successor = minValueNode(node->right);
            T successorData = successor->data;
            remove(successorData); // Recursively remove the successor
            node->data = successorData; // Copy the successor's value to the current node
        } else {
            // Case 2 and 3: Node with only one child or no child
            BstNode *child = (node->left != NULL) ? node->left : node->right;

            if (parent == NULL) {
                root = child; // Node to be deleted is root
            } else {
                if (node == parent->left) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
            delete node; // Delete the node
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(T data) {
        root = insert(root, data);
    }

    void inOrderTraversal() const {
        inOrderTraversal(root);
    }
    void removeNode(const T &t){
      remove(t);
    }

    // Destructor to handle memory deallocation
    ~BinarySearchTree() {
 
    }

};

int main() {
    BinarySearchTree<int> bst;
    int userInput;
    char exit;
    do{
      cout<<"\nPlease enter the number you wish to put into your binary tree: ";
      cin>>userInput;
      cout<<"\nDo you wish to add more numbers (Y/N): ";
      cin>>exit;
      bst.insert(userInput);
    }while(exit=='y' || exit=='Y');


    bst.inOrderTraversal(); 
    cout<<"\nPlease enter the number you wish to remove from tree: ";
    cin>>userInput;
    bst.removeNode(userInput);// Should print the numbers in ascending order
    bst.inOrderTraversal(); 

    return 0;
}
