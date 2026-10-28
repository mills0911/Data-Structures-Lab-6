#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string name;
    double rating;
    int frequency;
    int balanceFactor;
    
    Node* left;
    Node* right;

    Node(std::string name, double rating);
};

#endif
