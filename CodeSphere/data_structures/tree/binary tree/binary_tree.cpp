#include "binary_tree.hpp"

TreeNode * Tree::InsertRoot (int val)
{
    vRoot = new TreeNode (val);
    return vRoot;
}

void Tree::InsertRoot (TreeNode * pRoot) 
{
    vRoot = pRoot;
}

TreeNode * Tree::InsertLeft (TreeNode * pNode, int val)
{
    TreeNode * newNode = new TreeNode(val);
    
    pNode->left = newNode;
    
    return newNode;
}

void Tree::InsertLeft (TreeNode * pNode, TreeNode * pNewNode)
{
    pNode->left = pNewNode;
}

TreeNode * Tree::InsertRight (TreeNode * pNode, int val)
{
    TreeNode * newNode = new TreeNode(val);
    
    pNode->right = newNode;
    
    return newNode;
}

void Tree::InsertRight (TreeNode * pNode, TreeNode * pNewNode)
{
    pNode->left = pNewNode;
}
