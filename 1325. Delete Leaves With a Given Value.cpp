/*
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if it's parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you can't).

*/

class Solution {
public:
    TreeNode* helper(TreeNode* root,int target)
    {
        if(root==NULL)
            return NULL;
        if(root->left==NULL and root->right==NULL) // Leaf Node
        {
            if(root->val==target) // If leaf node is target
                return NULL;
            return root; // If leaf node is not target
        }
        root->left = helper(root->left,target); // Update the left pointer with watever was returned(NULL or existing node itself.
        root->right = helper(root->right,target);// Update the right pointer with watever was returned(NULL or existing node itself.
        if(root->left==NULL and root->right==NULL and root->val==target) // After left and right children are updated, once again check if they are NULL and current value is target
            return NULL;
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return helper(root,target);    
    }
};
