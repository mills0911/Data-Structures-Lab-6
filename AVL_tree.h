#include "node.h"

class AVL_tree{
private:
    Node* root;

    void deleteTree(Node* root);
    Node* AVL_tree::findNodeOrParent(std::string appName);
    Node* AVL_tree::findNodeOrParent(Node* curr, std::string appName);
public:
    AVL_tree();
    ~AVL_tree();
    void insertApp(std::string name, double rating);
};
