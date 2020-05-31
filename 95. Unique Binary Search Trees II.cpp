/**
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

We have to generate a list of left subtree's and right subtree's of vectors and then for each left subtree we have to loop thru right subtree's and create a full tree at the end. 

Idea is that left subtree will be low to i-1 and right subtree will be i+1 to high at any point.


* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> helper(int low,int high)
    {
        vector<TreeNode*> ans;
        if(low>high)
        {
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=low;i<=high;i++)
        {
            vector<TreeNode*> lefts = helper(low,i-1);
            vector<TreeNode*> rights = helper(i+1,high);
            for(auto left : lefts)
                for(auto right : rights)
                {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        return (n==0 ? vector<TreeNode*>() : helper(1,n));
    }
};
