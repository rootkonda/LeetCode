/*
We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

*/

class Solution {
public:
    bool helper(TreeNode* root)
    {
        bool left=false;
        bool right=false;
        if(root->left==NULL and root->right==NULL) //leaf node
            return root->val==1; // return true only when this node's value is 1
        if(root->left)
            left = helper(root->left);
        if(root->right)
            right=helper(root->right);
        
        if(!left) // when left is false, it means there is no 1 in left subtree so set the left subtree to NULL
            root->left=NULL;
        if(!right) // when right is false, it means there is no 1 in right subtree so set the right subtree to NULL
            root->right=NULL;
        
        return (left or right or root->val); // after processing left and right subtree, return true only when right or left subtree has 1 or current node's value is 1
    }
    TreeNode* pruneTree(TreeNode* root) 
    {
        if(!root)
            return root;
        helper(root);
        if(root->left==NULL and root->right==NULL) // For the root node, when left and right subtree has no 1 then check current node has 1 then return root or just return NULL
            return root->val==1 ? root : NULL;
        return root;
    }
};
