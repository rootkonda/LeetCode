/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

In order to be a lowest common ancestor it has to be a first parent/node where it should have found p and q in one of its left and right children. Since it is a recursion it obviously goes till the end and come back meaning it is a bottom-up approach.
*/

class Solution {
public:
    TreeNode* ans;
    int helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
            return false;
        int left = helper(root->left,p,q) ? 1 : 0;
        int right = helper(root->right,p,q) ? 1 : 0;
        int mid = (root==p or root==q) ? 1 : 0;
        
        if(mid+left+right>=2)
            ans = root;
        
        return (mid+left+right)>0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        helper(root,p,q);
        
        return ans;
    }
};
