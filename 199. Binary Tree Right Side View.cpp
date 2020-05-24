/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Explanation:
------------
At each level we have to only take the right most node. For this we have to store the children i.e left and right nodes for a given node into a queue and then keep number of elements we pushed to pop back later that many elements and last element we can push it to answer.
*/


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
            return ans;
        int temp=0;
        queue<TreeNode*> que;
        que.push(root);
        int n = 1;
        while(!que.empty())
        {
            while(n-- and !que.empty())
            {
                TreeNode* node = que.front();
                temp = node->val;
                if(node->left!=NULL) que.push(node->left) ;
                if(node->right!=NULL) que.push(node->right);
                que.pop();
            }
            ans.push_back(temp);
            n = (int)que.size();
        }
        return ans;
    }
};
