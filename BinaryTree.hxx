#include <iostream>
#include <climits>
#include <fstream>
#include "stack.hxx"


template <class T> 
class BST {

    struct BSTnode {
        BSTnode* parent;
        BSTnode* left;
        BSTnode* right;
        T key;
    };
    BSTnode* root;
public:
    BST():root(nullptr) {}
    ~BST() { delete_tree(root); }

    void delete_tree(BSTnode* node) {
        if(node != nullptr) {
            delete_tree(node->left);
            delete_tree(node->right);
            delete node;
        }
    }

    BSTnode* insert(BSTnode* node, const T& key) {
        if(node == nullptr) {
            node = new BSTnode;
            node->parent = nullptr;
            node->left = nullptr;
            node->right = nullptr;
            node->key = key;
        }else if(node->key <= key) {
            node->right = insert(node->right, key);
            node->right->parent = node;
        }else {
            node->left = insert(node->left, key);
            node->left->parent = node;
        }
        return node;
    }
    void insert(const T& key) {
	    root = insert(root, key);
    }
    
    BSTnode* searchRecursive(BSTnode* node, const T& key) {
        if(node->key == key) {
                return node;
        }else if(node->key < key) {
            return searchRecursive(node->right, key);
        }else if(node->key > key){
            return searchRecursive(node->left, key);
        }else return nullptr;
    }
    BSTnode* searchRecursive(const T& key) {
	    return searchRecursive(root, key);
    }
    
    BSTnode* search(const T& key) {
        BSTnode* node = root;
        while(node != nullptr) {
            if(key > node->key) {
                node = node->right; 
            }else if(key < node->key) {
                node = node->left;
            }else return node;
        } 
        return nullptr; 
    }

    T maximum(BSTnode* node) {
        if(node == nullptr) throw std::out_of_range("ERROR(maximum): NULL NODE\n");
        else if(node->right == nullptr) return node->key;
        else return maximum(node->right);
    }
    T maximum() { return maximum(root); }

    T minimum(BSTnode* node) {
        if(node == nullptr) throw std::out_of_range("ERROR(minimum): NULL NODE\n");
        else if(node->left == nullptr) return node->key;
        else return minimum(node->left);
    }
    T minimum() { return minimum(root); }

    int size(BSTnode* node) {  
        if(node == nullptr) return 0;  
        else return size(node->left) + size(node->right) + 1; 
    }
    int size() { return size(root); }

    int depth(BSTnode* node) {
        if(node == nullptr) return 0;
        else {
            int left_;
            int right_;
            left_ = depth(node -> left);
            right_ = depth(node -> right);
            if(left_ > right_) return left_ + 1;
            else return right_ + 1;
        }
    }
    int depth() { return depth(root); }

    void printInorder(BSTnode* node) {
       if(node != nullptr) {
            printInorder(node->left);
            std::cout << node->key << ' '; 
            printInorder(node->right);
        }  
    }
    void printInorder() { printInorder(root); }
    
    void IterativeinOrder() {
        Stack<BSTnode *,10000000> s; 
        BSTnode *node = root; 
        while (!s.empty() || node != nullptr){ 
     
            while (node !=  nullptr) {
                s.push(node); 
                node = node->left; 
            }
            node = s.top(); 
            s.pop(); 
            std::cout << node->key << ' '; 
            node = node->right; 
    
        }
    }

    void printPreorder(BSTnode* node) {
        if(node != nullptr) { 
            std::cout << node->key << ' '; 
            printPreorder(node->left);
            printPreorder(node->right);
        }
    }
    void printPreorder() { printPreorder(root); }

    void printPostorder(BSTnode* node) {
        if(node != nullptr) { 
            printPostorder(node->left);
            printPostorder(node->right);
            std::cout << node->key << ' '; 
        }
        
    }
    void printPostorder() { printPostorder(root); }

     void IterativePreorder() {
         BSTnode *node = root; 
        if (node != nullptr) {
            Stack<BSTnode*,10000000> s;
            s.push(node);

            while (!s.empty()) {
                node = s.top();
                std::cout << node->key << ' '; 
                s.pop();
                if (node->right)
                    s.push(node->right);
                if (node->left)
                    s.push(node->left);
            }
        }
    }

    void printTree(const std::string& pre, const BSTnode* node, bool isRight) {
        if( node != nullptr ) {
            std::cout << pre;
            std::cout << (isRight ? "├──" : "└──" );
            std::cout << node->key << '\n';
            printTree(pre + (isRight ? "│   " : "    "), node->right, true);
            printTree(pre + (isRight ? "│   " : "    "), node->left, false);
        }
    }
    void printTree() { printTree("", root, false); }
    
    bool isBST(BSTnode *node, int min, int max) {
        if(node != nullptr)
            return true;

        if (node->key <= min || node->key > max)
            return false;

        return ( isBST(node->left, min, node->key) && isBST(node->right, node->key, max) ) ? true : false;
    }
   bool isBST() { return isBST(root, INT_MIN, INT_MAX); }  
  

};

