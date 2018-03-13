#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

template<typename T> class Node {
  public: 
    T value;
    Node<T>* left;
    Node<T>* right;

    Node(T n) : value(n) {
      this->left = nullptr;
      this->right = nullptr;
    }
};

template<typename T> class BinaryTree {
  public:
    Node<T>* root;

    BinaryTree(T n) {
      this->root = new Node<T>(n);
    }

    bool exist(T n) {
      Node<T>* node = this->root;
      while (node != nullptr) {
        if (node->value == n) return true;
        if (node->value > n) node = node->left;
        else node = node->right;
      }
      return false;
    }

    void insert(T n) {
      Node<T>* node = this->root;
      while (true) {
        if (node->value == n) return;
        if (node->value > n) {
          if (node->left == nullptr) {
            node->left = new Node<T>(n);
            break;
          } else node = node->left;
        } else {
          if (node->right == nullptr) {
            node->right = new Node<T>(n);
            break;
          } else node = node->right;
        }
      }
    }
};


int main(){
  BinaryTree<int> bt(2);
  bt.insert(3);
  cout << bt.exist(3) << endl;
}
