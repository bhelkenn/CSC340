#ifndef __TREE_H__
#define __TREE_H__
#include <iostream>
#include <algorithm>
#include "node.h"

using namespace std;

template <class T>
class Tree {
  private:
    Node<T> *root;

    int height(Node<T> *node) {
		  if (node == NULL)
		    return 0;
		  else
		    return 1 + max(height(node->left), height(node->right));
		}
    int size(Node<T> *node) {
		  if (node == NULL)
		    return 0;
		  else
		    return 1 + size(node->left) + size(node->right);
		}
    void insert(Node<T> *node, T value) {
		  if (value < node->value) {
		    if (node->left == NULL)
		      node->left = new Node<T>(value);
		    else
		      insert(node->left, value);
		  }
		  else {
		    if (node->right == NULL)
		      node->right = new Node<T>(value);
		    else
		      insert(node->right, value);
		  }
		}
		bool search(Node<T> *node, T value) {
		  if (node == NULL)
		    return false;
		
		  if (node->value == value)
		    return true;
		  else if (value < node->value)
		    return search(node->left, value);
		  else
		    return search(node->right, value);
		}
		T* find(Node<T> *node, T value) {
			T *result = NULL;
		  if (node == NULL) {
				return NULL;
			}
		    
		  if (node->value == value) {
				result = &node->value;
			}
		  else if (value < node->value) {
				result = find(node->left, value);
			}
		  else {
				result = find(node->right, value);
			}
			
			return result;
		}

    void preorder_traversal(Node<T> *node) {
		  if(node != NULL) {
		    cout << node->value << " ";
		    preorder_traversal(node->left);
		    preorder_traversal(node->right);
		  }
		}
		void inorder_traversal(Node<T> *node) {
		  if(node != NULL) {
		    inorder_traversal(node->left);
		    cout << node->value << " ";
		    inorder_traversal(node->right);
		  }
		}
		void postorder_traversal(Node<T> *node) {
		  if(node != NULL) {
		    postorder_traversal(node->left);
		    postorder_traversal(node->right);
		    cout << node->value << " ";
		  }
		}
		
  public:
    Tree() {
    	root = NULL;
    }
    ~Tree() {
		  if (root != NULL) {
		    delete root;
		    root = NULL;
		  }
		}

    int height() {
		  return height(root);
		}
    int size() {
		  return size(root);
		}
		void insert(T value) {
		  if (root == NULL)
		    root = new Node<T>(value);
		  else
		    insert(root, value);
		}
    bool search(T value) {
		  return search(root, value);
		}
		T* find(T value) {
			return find(root, value);
		}
		
    void preorder_traversal() {
		  preorder_traversal(root);
		  cout << endl;
		}
		void inorder_traversal() {
		  inorder_traversal(root);
		  cout << endl;
		}
		void postorder_traversal() {
		  postorder_traversal(root);
		  cout << endl;
		}
};

#endif