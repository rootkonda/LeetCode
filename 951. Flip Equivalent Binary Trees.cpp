/**
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.

Store the nodes at every level for each tree and compare with another tree at every level. 
At any point of second tree comparision, if we cannot find a node in the level we traversed in tree 1 then return false or return true. 


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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        map<int,unordered_set<int>> nodes;
        queue<TreeNode*> r1;
        queue<TreeNode*> r2;
        if(root1==NULL and root2!=NULL)
            return false;
        else if(root1!=NULL and root2==NULL)
            return false;
        else if(root1==NULL and root2==NULL)
            return true;
        
        if(root1->val!=root2->val)
            return false;
        r1.push(root1);
        r2.push(root2);
        
        while(!r1.empty() and !r2.empty())
        {
            int n = r1.size();
            while(n--)
            {
                TreeNode* temp = r1.front();
                r1.pop();
                if(temp->left)
                {
                    nodes[temp->val].insert(temp->left->val);
                    r1.push(temp->left);
                }
                    
                if(temp->right)
                {
                    nodes[temp->val].insert(temp->right->val);
                    r1.push(temp->right);
                }
            }
            n = r2.size();
            while(n--)
            {
                TreeNode* temp = r2.front();
                r2.pop();
                
                if(temp->left)
                {
                    if(nodes[temp->val].insert(temp->left->val).second)
                        return false;
                    nodes[temp->val].erase(temp->left->val);
                    r2.push(temp->left);
                }
                if(temp->right)
                {
                    if(nodes[temp->val].insert(temp->right->val).second)
                        return false;
                    nodes[temp->val].erase(temp->right->val);
                    r2.push(temp->right);
                }
                if(nodes[temp->val].size())
                    return false;
                
            }
        }
        return true; 
    }
};


/*
[1,2,3,4,5,6]
[1,3,2,null,6,4,5,null,null,null,null,8,7]
[1,2,3,4,5,6,null,null,null]
[1,3,2,null,6,4,5,null,null,null,null,8,7]
[1,2,3,4,5,6,null,null,null,7,8]
[1,3,2,null,6,4,5,null,null,null,null,8,7]


*/
