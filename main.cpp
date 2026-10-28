// Imports
#include <iostream>
#include "AVL_tree.h"
int main(){
    
    // Make a pointer to a AVL tree THIS WILL HOLD ALL THE APPS
    AVL_tree* appTree = new AVL_tree();

    appTree->insertApp("Spotify", 4.6);
    
    appTree->updateApp("Spotify", 4.1);
    appTree->getAppInfo("Spotify");
    //getTopKApps

    
    delete appTree;
    return 0;
}