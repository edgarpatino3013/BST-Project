#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

bool epRecursive(Node* root, int currdepth, int& maxDepth){

//BASE CASE: root is pointing to nothing, children paths are equal size
    if (root == nullptr){
        return true;
    }

//CASE 1: current node has no children
    if (root->left == nullptr && root->right == nullptr){

        //if we have one node only
        if (maxDepth == -1){
            maxDepth = currdepth;
        }
        //else, compare to current depth
        return currdepth == maxDepth;
    }

    //TWO recursive calls at the same time, each going down a path 
    //returns boolean each iteration
    return epRecursive(root->left, currdepth+1, maxDepth) &&
    epRecursive(root->right, currdepth+1, maxDepth);

}


bool equalPaths(Node * root)
{
    // Add your code below
    int maxDepth = -1;
    return epRecursive(root, 0, maxDepth);

}

