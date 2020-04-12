/**
Find the sum of all left leaves in a given binary tree.

Idea is for every node check if its left child is not NULL and whether it is leaf node. Push the left and right nodes into stack. At the beginning pop the stack and process that.
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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        TreeNode* curr=root;
        stack<TreeNode*> st;
        int sum=0;
        st.push(root);
        while(!st.empty())
        {
            curr=st.top();
            st.pop();
            if(curr->left!=NULL)
            {
                st.push(curr->left);
                if(curr->left->left==NULL and curr->left->right==NULL)
                    sum+=curr->left->val;
            }
            if(curr->right!=NULL)
                st.push(curr->right);
        }
        return sum; 
    }
};
