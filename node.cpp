#include <string>
#include "node.h"

Node::Node(std::string name, double rating) {
    this->name = name;
    this->rating = rating;
    frequency = 1;
    int balanceFactor = 0;


    left = nullptr;
    right = nullptr;
}
