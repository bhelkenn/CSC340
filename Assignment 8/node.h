#ifndef __NODE_H__
#define __NODE_H__
#include <stddef.h>

template <class T>
class Node {
  public:
    Node() {
    	left = right = NULL;
    }
    Node(T v) {
    	value = v;
    	left = right = NULL;
    }
    ~Node() {
    	if (left != NULL) {
		    //delete left;
		    left = NULL;
		  }
		  if (right != NULL) {
		    //delete right;
		    right = NULL;
		  }
		}

    T value;
    Node<T> *left;
    Node<T> *right;
};

#endif