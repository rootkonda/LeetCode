/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

There are 3 cases to consider while deleting a node from BST.

Zero children. i.e. Leaf node - In this case, we dont need to worry because there are no nodes to adjust.
One child. - In this case, we have to just move up the right or left node(whichever is not NULL) to the current node and delete the old node.
Two children - In this case, first find the address of the minimum of right subtree and then update the current node's value to the minimum. Next, delete the minimum node from the right subtree. We can do this by calling the same method recursively and it will become either case 1 or case 2 above. Note that in this case, we can also find the address of maximum of left subtree, which might be a leaf node.
*/


class Solution {
public:
    TreeNode* FindMin(TreeNode* root) // Finding minimum in right subtree
    {
        //Minimum value can be found either in the leaf node of left subtree or at the beginning of the right subtree
        if(root->left==NULL) // If not left child then the current node is the minimum value
            return root;
        return FindMin(root->left); // If there is a left child then keep recursing until the left child is NULL.
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
            return root;
        if(key<root->val) // Goto left 
            root->left = deleteNode(root->left,key);
        else if(key>root->val)//Goto right
            root->right = deleteNode(root->right,key);
        else
        {
            //No children.i.e. Leaf node
            if(root->left==NULL and root->right==NULL)
            {
                delete root;
                root=NULL;
            }
            else if(root->left==NULL)// Left child is null but not right 
            {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right==NULL) // right child is null but not left
            {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else // If the node has both the children
            {
                TreeNode* temp = FindMin(root->right); //Find the minimum in the right sub tree
                root->val = temp->val; // Update the current node's value to the minimum node value;
                root->right = deleteNode(root->right,temp->val); // Delete the minimum node(which might have either one child or no child)
            }
        }
        return root; 
    }
};
