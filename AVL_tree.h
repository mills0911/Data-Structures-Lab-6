#include "node.h"
#include <string>

class AVL_tree{
private:
    Node* root;

    void deleteTree(Node* root);
    void rotateLeft();
    void rotateRight();
    void recalculateBalance();
    Node* findNode(std::string appName);
    // Helper Functions
    Node* findNode(Node* curr, std::string appName);
    Node* insertApp(std::string name, double rating, Node* curr);

public:
    AVL_tree();
    ~AVL_tree();
    void insertApp(std::string name, double rating);
    void updateApp(std::string name, double newRating);
    void getAppInfo(std::string name);
};
