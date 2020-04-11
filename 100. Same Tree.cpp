/**
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

First compare values of two nodes. Next take the left node's of both lists and right node's of both of them into a stack or a vector
when one of them is NULL or values doesnt match return false else return true.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> st1,st2;
        if(!p and !q)
            return true;
        else if(!p or !q)
            return false;
        TreeNode *np,*nq;
        st1.push_back(p);
        st2.push_back(q);
        while(st1.empty()==false and st2.empty()==false)
        {
            np=st1.back();
            nq=st2.back();
            st1.pop_back();
            st2.pop_back();
            if(np->val != nq->val)
                return false;
            if(np->right!=NULL and nq->right!=NULL)
            {
                st1.push_back(np->right);
                st2.push_back(nq->right);
            }
            else if(np->right!=NULL or nq->right!=NULL)
                return false;
            if(np->left!=NULL and nq->left!=NULL)
            {
                st1.push_back(np->left);
                st2.push_back(nq->left);
            }
            else if(np->left!=NULL or nq->left!=NULL)
                return false;
        }
        if(st1.empty() and st2.empty())
            return true;
        else
            return false;
    }
};
