#include "AVL_tree.h"
#include <iostream>

// Helper functions
Node* AVL_tree::findNodeOrParent(std::string appName) {return findNodeOrParent(root, appName);}

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
Node* AVL_tree::findNodeOrParent(Node* curr, std::string appName){ // Get the parent of the app to add        
    if (curr == nullptr) return nullptr;
    if (curr->name == appName){      // check equal
        return curr;
    }
    else if ((curr->name > appName)) {     // check left node, 
        if (curr->left == nullptr) return curr; 
        return findNodeOrParent(curr->left, appName);
    }
    else {     // go right
        if (curr->right == nullptr) return curr;  
        return findNodeOrParent(curr->right, appName);
    }

    return nullptr;
}

void AVL_tree::insertApp(std::string name, double rating){
    // Check if its the first node added
    if (root == nullptr){
        root = new Node(name, rating);
        return;
    }

    // if it is not root then find where to add
    Node* parent = findNodeOrParent(name);

    // check if parent is a duplicate
    if (parent->name == name) { 
        std::cout<<"Duplicate Detected"<<std::endl;
        parent->frequency++;
        return;
    } 
    // check if the node should be added to the left then add
    else if (parent->name > name){ 
        parent->left = new Node(name, rating);
    }
    // add node to right
    else{ 
        parent->right = new Node(name, rating);
    }
}
