#include "main.h"

int main(int argc, const char * argv[]) {
            
    Tree * tree = new Tree();
    TreeNode *   root;
    TreeNode *   rootleft;
    TreeNode *   rootright;
    TreeNode *   rootleftleft;
    TreeNode *   rootleftright;
    TreeNode *   rootrightleft;
    
    root = tree->InsertRoot(1);
    rootleft = tree->InsertLeft (root,2);
    rootright = tree->InsertRight (root,3);
    
    rootleftleft = tree->InsertLeft (rootleft,4);
    rootleftright = tree->InsertRight (rootleft,5);
    
    rootrightleft = tree->InsertLeft (rootright,6);
    
    for (auto num : morrisTraversal (root)) {
        
        std::cout <<num<<" ";
    }
    
    return 0;
}
