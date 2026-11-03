#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "AVL_tree.h"

// Helper functions
Tnode *AVL_tree::findNode(const std::string &appName) { return findNode(root, appName); }
void AVL_tree::insertApp(const std::string &name, double rating) { root = insertApp(name, rating, root); }

// Creation
AVL_tree::AVL_tree() : root(nullptr) {};

// Deletion
AVL_tree::~AVL_tree()
{
    deleteTree(root);
}
void AVL_tree::deleteTree(Tnode *root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Function for finding a node; app given app name
Tnode *AVL_tree::findNode(Tnode *node, const std::string &appName)
{
    if (node == nullptr)
        return nullptr;
    if (node->name == appName)
        return node;
    if (node->name > appName)
        return findNode(node->left, appName);
    return findNode(node->right, appName);
}

Tnode *AVL_tree::insertApp(const std::string &name, double rating, Tnode *node)
{
    // if Nullptr, then location to add to has been found
    if (node == nullptr)
        return new Tnode(name, rating);

    if (node->name == name)
        throw std::invalid_argument("Duplicated Detected");
    else if (node->name > name)
        node->left = insertApp(name, rating, node->left);
    else
        node->right = insertApp(name, rating, node->right);

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1)
    {
        if (name < node->left->name)
        { // Left-left
            return rotateRight(node);
        }
        node->left = rotateLeft(node->left); // Left-right
        return rotateRight(node);
    }

    if (balance < -1)
    {
        if (name > node->right->name)
        { // Right-right
            return rotateLeft(node);
        }
        node->right = rotateRight(node->right); // Right-left
        return rotateLeft(node);
    }

    return node;
}

int AVL_tree::getBalance(Tnode *node)
{
    if (node == nullptr)
        return 0;
    else
        return height(node->left) - height(node->right);
}

// Update Rating of node
void AVL_tree::updateApp(const std::string &name, double newRating)
{
    // Find node, check if it exist, update
    Tnode *nodeToUpdate = findNode(name);
    if (nodeToUpdate == nullptr)
        throw std::out_of_range("Node does not exist\n");

    nodeToUpdate->rating = newRating;
}

void AVL_tree::getAppInfo(const std::string &name)
{
    // Find node, check if it exist, Print
    Tnode *node = findNode(name);
    if (node == nullptr)
        throw std::out_of_range("Node does not exist\n");

    std::cout << "Rating: " << node->rating
              << ", Frequency: " << node->frequency
              << std::endl;
}

int AVL_tree::height(Tnode *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}
Tnode *AVL_tree::rotateLeft(Tnode *rotPoint)
{ // Rotate from given node
    auto R = rotPoint->right;
    auto RL = R->left;

    // Rotation
    R->left = rotPoint;
    rotPoint->right = RL;

    // Update Height
    rotPoint->height = 1 + std::max(height(rotPoint->left), height(rotPoint->right));
    R->height = 1 + std::max(height(R->left), height(R->right));

    return R;
}
Tnode *AVL_tree::rotateRight(Tnode *rotPoint)
{ // Rotate from given node
    auto L = rotPoint->left;
    auto LR = L->right;

    // Rotation
    L->right = rotPoint;
    rotPoint->left = LR;

    // Update Height
    rotPoint->height = 1 + std::max(height(rotPoint->left), height(rotPoint->right));
    L->height = 1 + std::max(height(L->left), height(L->right));

    return L;
}

void AVL_tree::recalculateBalance() {}
