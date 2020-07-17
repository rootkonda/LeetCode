/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

*/


class Solution {
public:
    vector<int> rmv;
    vector<TreeNode*> ans;
    int count=0;
    void helper(TreeNode* root,TreeNode* parent,int dir)
    {
        if(count==0) // When there are no more elements to delete then stop
            return;
        else if(rmv[root->val]) // If current element is to be removed
        {
            count--;
            if(parent and dir==-1) // Update the parent's left child to NULL
                parent->left = NULL;
            else if(parent and dir==1) // Update the parent's right child to NULL
                parent->right = NULL;
            if(root->left and !rmv[root->left->val]) // As we remove this node, check if left child should remain if so then add it to answer
                ans.push_back(root->left);
            if(root->right and !rmv[root->right->val]) // As we remove this node, check if right child should remain if so then add it to answer
                ans.push_back(root->right);
        }
        // Recurse until we have elements to be deleted
        if(root->left) 
            helper(root->left,root,-1);
        if(root->right)
            helper(root->right,root,1);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        rmv.resize(1001,0); // Max 1000 elements as given
        count = to_delete.size();
        for(auto n : to_delete)
            rmv[n]=1; // flag to check in O(1) time if an element should be deleted
        helper(root,NULL,0);
        if(rmv[root->val]==0) // If the root node should remain then add it to answer.
            ans.push_back(root);
        return ans;
    }
};
