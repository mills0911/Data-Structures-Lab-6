#pragma once

#include <string>

#include "Tnode.h"
#include "MaxHeap.h"

class AVL_tree {
private:
    Tnode* root;
    int getBalance(Tnode* node);
    int height(Tnode* node);
    void deleteTree(Tnode* node);
    void recalculateBalance();
    Tnode* rotateLeft(Tnode* rotationPoint);
    Tnode* rotateRight(Tnode* rotationPoint);

    Tnode* findNode(Tnode* node, const std::string& appName);
    Tnode* insertApp(const std::string& name, double rating, Tnode* node);

public:
    AVL_tree();
    ~AVL_tree();
    Tnode* findNode(const std::string& appName);

    void insertApp(const std::string& name, double rating);
    void updateApp(const std::string& name, double newRating);
    void getAppInfo(const std::string& name);
    void getTopKApps(int numToPrint);
};
