#include <string>
#include "node.h"

Node::Node(std::string name, double rating) {
    std::string name{name};
    double rating{rating};
    int frequency = 1;

    left = nullptr;
    right = nullptr;
}