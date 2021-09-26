#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>
#include <chrono>    
#include <cstdio>   
#include <cmath>
#include <numeric>
#include <vector>
#include "BinaryTree.hxx"
template <class T> 
void generate(BST<T> &tree, int n, int max) {
    std::uniform_int_distribution<T> dist1 ( 0, max );
    std::mt19937 gen ( time ( NULL ) );
        
    for( int i = 0; i < n; i++ ) {
       tree.insert(dist1(gen));
    }
}
template <class T> 
void generateAscending(BST<T> &tree, int n, int max) {
 
    for( int i = 0; i < n; i++ ) {
       tree.insert(n);
    }
}

template <class T> 
void generateDescending(BST<T> &tree, int n, int max) {
 
    for( int i = n; i > 0; i-- ) {
       tree.insert(n);
    }
}

template <class T> 
void information(BST<T> &tree) {
    
    std::cout << "-INFORMATION-\n";
    std::cout << "IS BST ? : " << ((tree.isBST())? "YES" : "NO" )<< '\n';
    std::cout << "SIZE : " << tree.size() << '\n';
    std::cout << "DEPTH : " << tree.depth() << '\n';
    std::cout << "MINIMUM : " << tree.minimum() << '\n';
    std::cout << "MAXIMUM : " << tree.maximum() << '\n';

}
template <class T> 
void test_inorder(BST<T> &tree) {

    auto start = std::chrono::high_resolution_clock::now();
        std::streambuf *old = std::cout.rdbuf(0);
        tree.printInorder(); 
        std::cout.rdbuf(old);
    auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
    std::cerr << "IN ORDER RECURSIVE elapsed time[s] =" << diff.count() << std::endl;
   
    auto iostart2 = std::chrono::high_resolution_clock::now(); 
        std::streambuf *old2 = std::cout.rdbuf(0);
        tree.IterativeinOrder(); 
        std::cout.rdbuf(old2);
    auto ioend2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> io2 = ioend2 - iostart2;
    std::cerr << "IN ORDER ITERATIVE elapsed time[s] =" << io2.count() << std::endl;

}

template <class T> 
void test_preorder(BST<T> &tree) {
    auto iostart = std::chrono::high_resolution_clock::now(); 
        std::streambuf *old = std::cout.rdbuf(0);
        tree.printPreorder(); 
        std::cout.rdbuf(old);
    auto ioend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> io = ioend - iostart;
    std::cerr << "PRE ORDER RECURSIVE elapsed time[s] =" << io.count() << std::endl;
   
    auto iostart2 = std::chrono::high_resolution_clock::now(); 
        std::streambuf *old2 = std::cout.rdbuf(0);
        tree.IterativePreorder(); 
        std::cout.rdbuf(old2);
    auto ioend2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> io2 = ioend2 - iostart2;
    std::cerr << "PRE ORDER ITERATIVE elapsed time[s] =" << io2.count() << std::endl;


}

template <class T> 
void test_searchMaxKey(BST<T> &tree, const T &key) {
    std::cout << "SEARCH MAXIMUM : " << tree.maximum() << '\n';
        auto iostart = std::chrono::high_resolution_clock::now(); 
            if(tree.search(key) != nullptr)std::cout<<"YES\n";
            else std::cout<<"NO\n";
    auto ioend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> io = ioend - iostart;
    std::cerr << "SEARCH RECURSIVE elapsed time[s] =" << io.count() << std::endl;
   
    auto iostart2 = std::chrono::high_resolution_clock::now(); 
            if(tree.searchRecursive(key) != nullptr)std::cout<<"YES\n";
            else std::cout<<"NO\n";
    auto ioend2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> io2 = ioend2 - iostart2;
    std::cerr << "SEARCH ITERATIVE elapsed time[s] =" << io2.count() << std::endl;

}