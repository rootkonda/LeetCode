/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Inorder traversal gives us the sorted order of BST so every element should be greater than previous element. Hence just remember the previous element and take the difference between current and previous element.

*/
class Solution {
public:
    long last = 0;
    bool prev = false; // For the first time, previous value will not be there so it is false and rest of the times it will be true
    bool helper(TreeNode* root)
    {
        if(root->left==NULL and root->right==NULL)
        {
            if(!prev or root->val-last>0)
            {
                last = root->val;
                prev = true;
                return true;
            }
                
            return false;
        }
        if(root->left!=NULL and !helper(root->left))
            return false;
        
        if(!prev or root->val-last>0)
        {
            last = root->val;
            prev = true;
        }     
        else
            return false;
        
        if(root->right!=NULL and !helper(root->right))
            return false;
        
        return true;   
    }
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL or root->left==NULL and root->right==NULL)
            return true;
        return helper(root);        
    }
};

/*

[5,1,18,null,null,16,19,null,17,null]
[5,1,4,null,null,3,6]
[2,1,3]
[-1,-3]
[-2147483648,-2147483648]
[-2147483648,null,2147483647]

*/
