/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Just recurse left and right and make sure to keep track of the path string and pass it on every recursive call. When we encounter leaf node, add the string available at that time to our answer.
*/



class Solution {
public:
    vector<string> ans;
    void helper(TreeNode* root,string curr)
    {
        if(!root->left and !root->right)
        {
            curr.append(to_string(root->val));
            ans.push_back(curr);
        }
        curr.append(to_string(root->val)+"->");
        if(root->left)
            helper(root->left,curr);
        if(root->right)
            helper(root->right,curr);
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if(!root)
            return ans;
        helper(root,"");
        return ans;
    }
};
