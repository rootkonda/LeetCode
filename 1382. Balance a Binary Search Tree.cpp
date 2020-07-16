/*
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.


https://csactor.blogspot.com/2018/08/dsw-day-stout-warren-algorithm-dsw.html
https://leetcode.com/problems/balance-a-binary-search-tree/discuss/541785/C%2B%2BJava-with-picture-DSW-O(n)orO(1)
*/
/**
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
    int makevine(TreeNode* grand)
    {
        auto curr = grand->right;
        int count=0;
        while(curr)
        {
            if(curr->left)
            {
                auto temp = curr;
                curr = curr->left;
                temp->left = curr->right;
                curr->right = temp;
                grand->right = curr;
            }
            else
            {
                count++;
                grand = curr;
                curr = curr->right;
            }
        }
        return count;
    }
    void compress(TreeNode* grand,int n)
    {
        auto curr = grand->right;
        while(n-->0)
        {
            auto temp = curr;
            curr = curr->right;
            grand->right = curr;
            temp->right = curr->left;
            curr->left = temp;
            grand = curr;
            curr = curr->right;
        }
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        TreeNode grand;
        grand.right = root;
        int count = makevine(&grand);
        int n = pow(2, int(log2(count + 1))) - 1;; // Number of nodes to be closely balanced BST
        compress(&grand,count-n);
        for(n=n/2;n>0;n/=2)
            compress(&grand,n);
        return grand.right;
    }
};
