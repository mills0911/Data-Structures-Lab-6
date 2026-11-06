// Imports
#include <iostream>
#include <stdexcept>
#include "AVL_tree.h"
int main(){
    
    // Make a pointer to a AVL tree THIS WILL HOLD ALL THE APPS
    AVL_tree* appTree = new AVL_tree();
    try{
        appTree->insertApp("Spotify", 4.6);
        appTree->insertApp("Youtube", 4.9);
        appTree->insertApp("Data", 4.2);

        appTree->updateApp("Spotify", 4.1);

        appTree->getAppInfo("Spotify");
        appTree->getAppInfo("Youtube");
        appTree->getAppInfo("Data");
        appTree->getAppInfo("Youtube");
        
    } catch(const std::out_of_range& error){
        std::cerr << error.what() << '\n';
    } catch(const std::invalid_argument& error){
        std::cerr << error.what() << '\n';
    }

    //getTopKApps
	appTree->getTopKApps(2);
    
    delete appTree;
    return 0;
}   


