
#include <string>

class Tnode {
public:
    std::string name;
    double rating;
    int frequency;
    int height;
    
    Tnode* left;
    Tnode* right;

    Tnode(std::string name, double rating);
};


