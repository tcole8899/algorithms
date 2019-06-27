#include "BST.hpp"

BST::BST() {
  root = nullptr;
}

BST::~BST() {}

Node* BST::insert(int data, Node* n) {
  if (!n) {
    return new Node(data);
  } else if (data < n->data) {
    n->left = insert(data, n->left);
  } else if (data > n->data) {
    n->right = insert(data, n->right);
  }
  return n;
}

void BST::insert(int data) {
  root = insert(data, root);
}

bool BST::is_empty() {
  return !root;
}

bool BST::search(int data, Node* n) {
  if (!n)
    return false;
  else if (data == n->data)
    return true;
  else if (data < n->data)
    return search(data, n->left);
  else
    return search(data, n->right);
}

bool BST::search(int data) {
  return search(data, root);
}

Node* BST::remove(int data, Node* n) {
    if(!n)
        return n;
    else if(data == n->data){
        //no children
        if(!(n->left) && !(n->right)) {
            return n;
        }
        //one child
        else if(!(n->left) xor !(n->right)){ 

            if(!(n->left)){ 
                n->data = n->right->data;
                return n->right;
            }
            else {
                n->data = n->left->data;
                return n->left;
            }

        }
        //two children
        else{
            if(!n->right->left){
                n->data = n->right->data;
                return n->right;
            }
            else{
                Node* temp = n;
                n = n->right;
                while(n->left){
                    n = n->left;
                }
                n->data = temp->data;
                return temp->left;
            } 

        }
    }   
    else if(data < n->data)
        return remove(data, n->left);
    else if(data > n->data)
        return remove(data, n->right);
}

void BST::remove(int data) {
    delete remove(data, root);
}

int max(int a, int b) {
  return (a > b) ? a : b;
}
int BST::height(Node* n) {
  return (!n) ? -1 : 1 + max(height(n->left), height(n->right));
  if (!n)
    return -1;
  return 1 + max(height(n->left), height(n->right));
}

int BST::height() {
  return height(root);
}

void BST::clear(Node* n) {}

void BST::clear() {}

void BST::preorder(Node* n, std::ostream& oss) {}

void BST::preorder(std::ostream& oss) {}

void BST::inorder(Node* n, std::ostream& oss) {}

void BST::inorder(std::ostream& oss) {}

void BST::postorder(Node* n, std::ostream& oss) {}

void BST::postorder(std::ostream& oss) {}
