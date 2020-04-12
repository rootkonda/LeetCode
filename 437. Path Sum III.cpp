/**
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Approach - For a given node, calculate the total sum starting from that node till leaf for both left and right. Each iteration, check if sum==total.
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
    int calculate(TreeNode* root, int sum, int total)
    {
        if(root==NULL)
            return 0;
        int curr = total+root->val;     
        return (sum==curr)+calculate(root->left,sum,curr)+calculate(root->right,sum,curr);  
    }
    int pathSum(TreeNode* root, int sum) 
    {
        if(root==NULL)
            return 0;
        return calculate(root,sum,0)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};
