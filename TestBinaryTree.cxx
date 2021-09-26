#include "TestBinaryTree.hxx"

  
int main() {
std::cout << std::fixed << std::setprecision(9) << std::left;

    BST<int> tree, t100k, tree10k, tree100k, Ascending10k, Descending10k;
    
    std::cout<<std::string(50, '*')<<'\n';
    generate(tree, 10, 100);
    tree.printTree();
    information(tree);

    std::cout<<std::string(50, '*')<<'\n';
    std::cout<<"GENERATE 100k TREE:\n";
    generate(t100k, 100000, 100000);
    information(t100k);
    
    std::cout<<std::string(50, '*')<<'\n';
    generate(tree10k, 10000, 100000);
    std::cout << "-TEST IN ORDER ITERATIVE VS RECURSIVE-\n";
    std::cout << "\tIN ORDER ITERATIVE 10k: \n";
    test_inorder(tree10k);

    std::cout<<std::string(50, '*')<<'\n';
    generate(tree100k, 100000, 1000000);
    std::cout << "\tIN ORDER ITERATIVE 100k: \n";
    test_inorder(tree100k);

    std::cout<<std::string(50, '*')<<'\n';
    std::cout << "-TEST IN ORDER ITERATIVE VS RECURSIVE (Ascending)-\n";
    std::cout << "\tIN ORDER ITERATIVE 10k: (Ascending)\n";
    generateAscending(Ascending10k, 10000, 100000);
    test_inorder(Ascending10k);

    std::cout<<std::string(50, '*')<<'\n';
    std::cout << "-TEST IN ORDER ITERATIVE VS RECURSIVE (Descending)-\n";
    std::cout << "\tIN ORDER ITERATIVE 10k: (Descending)\n";
    test_inorder(Descending10k);

    std::cout<<std::string(50, '*')<<'\n';
    std::cout << "-TEST PRE ORDER ITERATIVE VS RECURSIVE-\n";
    std::cout << "\tPRE ORDER ITERATIVE 10k: \n";
    test_inorder(tree10k);

    std::cout<<std::string(50, '*')<<'\n';
    std::cout << "\tPRE ORDER ITERATIVE 100k: \n";
    test_preorder(tree100k);

    std::cout<<std::string(50, '*')<<'\n';
    std::cout << "-TEST PRE ORDER ITERATIVE VS RECURSIVE (Ascending)-\n";
    std::cout << "\tPRE ORDER ITERATIVE 10k: (Ascending)\n";
    test_preorder(Ascending10k);

    std::cout<<std::string(50, '*')<<'\n';
    std::cout << "-TEST PRE ORDER ITERATIVE VS RECURSIVE (Descending)-\n";
    std::cout << "\tPRE ORDER ITERATIVE 10k: (Descending)\n";
    test_preorder(Descending10k);

    std::cout<<std::string(50, '*')<<'\n';
    std::cout << "-SEARCH MAXIMUM KEY 100k ITERATIVE VS RECURSIVE-\n";
    test_searchMaxKey(tree100k, tree100k.maximum());

}