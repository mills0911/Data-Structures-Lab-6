#include "AVL_tree.h"
#include <iostream>

// Helper functions
Node* AVL_tree::findNode(std::string appName) {return findNode(root, appName);}
void AVL_tree::insertApp(std::string name, double rating){insertApp(name, rating, root);}

// Creation
AVL_tree::AVL_tree(){
    this->root = nullptr;
}

// Deletion
void AVL_tree::deleteTree(Node* root){
    if (root !=nullptr){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
AVL_tree::~AVL_tree(){
    deleteTree(root);
}


// Function for finding parents of an app given app name
Node* AVL_tree::findNode(Node* curr, std::string appName){ // Get the parent of the app to add        
    if (curr == nullptr) return nullptr;
    if (curr->name == appName){      // check equal
        return curr;
    }
    else if ((curr->name > appName)) {     // check left node, 
        if (curr->left == nullptr) return curr; 
        return findNode(curr->left, appName);
    }
    else {     // go right
        if (curr->right == nullptr) return curr;  
        return findNode(curr->right, appName);
    }

    return nullptr;
}

Node* AVL_tree::insertApp(std::string name, double rating, Node* curr){
    // Basic Insertion
    if (root == nullptr){
        root = new Node(name, rating);
        return;
    }
    if (curr->name == name)        // Check Duplicate
        throw std::invalid_argument("Duplicated Dected");
    else if (curr->name > name){   // Check + Go Left Node
        insertApp(name, rating, curr->left);
        curr->balanceFactor++;
    }
    else{                          // Go Right Node
        insertApp(name, rating, curr->right);
        curr->balanceFactor--;
    }

    // Checking BalanceFactor
}

void AVL_tree::updateApp(std::string name, double newRating){
    // Find node and check if it exist
    Node* nodeToUpdate = findNode(name);
    if (nodeToUpdate == nullptr) throw std::invalid_argument("Node does not exist\n");

    // If it does exist
    nodeToUpdate->rating = newRating;

    // Add code to make MaxHeap sort    
}

void AVL_tree::getAppInfo(std::string name){
    // Find node and check if it exist
    Node* node = findNode(name);
    if (node == nullptr) throw std::invalid_argument("Node does not exist\n");

    // If it does exist
    std::cout << "Rating: " << node->rating 
        << ", Frequency: " << node->frequency
        << std::endl;

}

void AVL_tree::rotateLeft(){}
void AVL_tree::rotateRight(){}
void AVL_tree::recalculateBalance(){}