#include "main.h"

std::vector<int> morrisTraversal (TreeNode * pRoot) {
    
    TreeNode * curNode = pRoot;
    TreeNode * rightmostnode;
    TreeNode * newCurNode;
    std::vector<int> resVector;
    
    while (curNode) {
        
        if (curNode->left) {
            
            /**
             * If the left child is there, make the current node the right child of the right most node in its left subtree.
             * Then go to  the root of the left subtree
             */
            rightmostnode = newCurNode = curNode->left;
            
            while (rightmostnode->right) {
                
                rightmostnode = rightmostnode->right;
            }
            
            rightmostnode->right = curNode;
            curNode->left = nullptr;
            curNode = newCurNode;
            
        } else {
            
            /**
             * Add the current node to the anser, and go to the right node
             */
            resVector.push_back(curNode->val);
            curNode = curNode->right;
        }
    }
    
    return resVector;
}
