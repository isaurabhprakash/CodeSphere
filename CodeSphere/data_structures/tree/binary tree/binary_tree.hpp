#ifndef binary_tree_hpp
#define binary_tree_hpp

class TreeNode {
 
public:
    TreeNode () : val(0),left(nullptr), right(nullptr) {}
    TreeNode (int x) : val(x),left(nullptr), right(nullptr) {}
    TreeNode (int x, TreeNode * left, TreeNode * right) : val(x),left(left), right(right) {}

    int val;
    TreeNode *  left;
    TreeNode *  right;
};

class Tree {
    
public :
    Tree () : vRoot (nullptr) {}
    
    TreeNode *  InsertRoot (int val);
    void        InsertRoot (TreeNode * pRoot);
    
    TreeNode *  InsertLeft (TreeNode * pNode, int val);
    void        InsertLeft (TreeNode * pNode, TreeNode * pNewNode);
    
    TreeNode *  InsertRight (TreeNode * pNode, int val);
    void        InsertRight (TreeNode * pNode, TreeNode * pNewNode);
    
private:
    TreeNode *  vRoot;
};

#endif //binary_tree_hpp
