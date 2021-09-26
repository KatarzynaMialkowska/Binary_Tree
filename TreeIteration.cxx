#include "BinaryTree.hxx"


int main() {

    BST<int> tree;
    int n = 0, x;
    std::cin>>n;
    while(n != 0) {
        std::cin>>x;
        tree.insert(x);
        --n;
    }
    tree.printTree();
   // std::cout<<tree.isBST();
    // std::cout<<
    // tree.size()<<" "<<
    // tree.depth()<<" "<<
    // tree.minimum()<<" "<<
    // tree.maximum()<<'\n';
    
    std::cout << "Iterative in order: \n";
    tree.IterativeinOrder();

    // for(int i = 1; i<9; i++) {
    //     if(tree.search(i) != nullptr)std::cout<<"Yes\n";
    //     else std::cout<<"No\n";
    // }

}