/*
Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.

https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal
https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/271774/C%2B%2B-8ms-beat-100-with-picture-explanation
*/

class Solution {
public:
    int moves=0;
    int get(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int left = get(root->left);
        int right = get(root->right);
        moves+=abs(left)+abs(right);
        return root->val+left+right-1;
    }
    int distributeCoins(TreeNode* root) 
    {
        get(root);
        return moves;
    }
};
