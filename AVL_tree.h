#include "node.h"
#include <string>

class AVL_tree{
private:
    Node* root;

    void deleteTree(Node* root);
    Node* findNodeOrParent(std::string appName);
    Node* findNodeOrParent(Node* curr, std::string appName);
public:
    AVL_tree();
    ~AVL_tree();
    void insertApp(std::string name, double rating);
    void updateApp(std::string name, double newRating);
    void getAppInfo(std::string name);
};
