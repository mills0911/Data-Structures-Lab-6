// Imports
#include <iostream>
#include <stdexcept>
#include "AVL_tree.h"
int main()
{
    
    // Make a pointer to a AVL tree THIS WILL HOLD ALL THE APPS
    AVL_tree* appTree = new AVL_tree();
    try
		{
		std::cout << "insertApp(\"Spotify\", 4.6) \n";
        appTree->insertApp("Spotify", 4.6);
        std::cout << "insertApp(\"Apple Music\", 4.5) \n";
        appTree->insertApp("Apple Music", 4.5);
        std::cout << "insertApp(\"Youtube\", 4.7) \n";
        appTree->insertApp("Youtube", 4.7);

        std::cout << "updateApp(\"Spotify\", 4.8) \n";
        appTree->updateApp("Spotify", 4.8);

        std::cout<<"getAPPInfo(\"Spotify\")=>";
		appTree->getAppInfo("Spotify");

		std::cout<<"getTopKApps(2) ";
		appTree->getTopKApps(2);
        
    	} 
	catch(const std::exception& e)
		{
		std::cerr<<e.what()<< '\n';
    	}

    delete appTree;
	return 0;
}   


