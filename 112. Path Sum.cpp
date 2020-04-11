/**
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Approach:

Start with the root node and then go to the left and then to the right if left subtree does not have sum.
Whenever we go left or right, make sure to subtract the node's value with sum.**/

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
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool ans=false;
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root!=NULL and root->left==NULL and root->right==NULL)
        {
            if((sum-root->val)==0)
                return true;
            else
                return false;
        }
        if(root!=NULL)
        {
            ans = hasPathSum(root->left,sum-root->val);
            if(!ans)
                ans = hasPathSum(root->right,sum-root->val);
        }
        return ans;
    }
};
