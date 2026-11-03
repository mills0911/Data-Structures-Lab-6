#include <string>
#include "Tnode.h"

Tnode::Tnode(std::string name, double rating) {
    this->name = name;
    this->rating = rating;
    frequency = 1;
    height = 1;

    left = nullptr;
    right = nullptr;
}
