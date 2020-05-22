/*
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Convert the tree to comma-delimited string using pre-order traversal.
After each left and right subtree traversal, keep track of its count and if it happens again then add it to the answer. To avoid adding multiple times add it only when count is 2.
*/

class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string,int> count;
    string helper(TreeNode* root)
    {
        if(root==NULL)
            return "X";
        string serial = to_string(root->val);
        serial+=",";
        serial+=helper(root->left);
        serial+=",";
        serial+=helper(root->right);
        count[serial]++;
        if(count[serial]==2)
            ans.push_back(root);
        return serial;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        helper(root);
        return ans;
    }
};
