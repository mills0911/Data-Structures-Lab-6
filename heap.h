#ifndef HEAP_H
#define HEAP_H

#include "node.h"

class HEAP {
private:
    Node* root;
    int size;

public:
    HEAP();
    //~HEAP();
    void instertApp(std::string name, double rating);
    void updateApp(std::string name, double rating){}

    void getAppInfo(std::string name){}
    void getTopApps(int numToPrint){}
};

#endif
