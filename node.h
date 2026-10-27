#ifndef NODE_H
#define NODE_H

class Node {
public:
    std::string name;
    double rating;
    int frequency;
    
    Node* left;
    Node* right;

    Node(std::string name, double rating);
};

#endif