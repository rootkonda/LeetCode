/**
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Approach:
For each node:
1. If there is a left child, add 1 to left and recursively goto left.
2. If there is a right child add 1 to right and recursively goto right.
3. After processing right and left, calculate maximum of current answer and left+right.
4. Return maximum of left or right.

**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int calculate(TreeNode* root)
    {
        int left = 0;
        int right = 0;
        if(root==NULL)
            return 0;
        if(root->left==NULL and root->right==NULL)
            return 0;
        if(root->left!=NULL)
            left = 1+calculate(root->left);
        if(root->right!=NULL)
            right = 1+calculate(root->right);
        
        ans = max(ans, left+right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        calculate(root);
        return ans;
    }
};
