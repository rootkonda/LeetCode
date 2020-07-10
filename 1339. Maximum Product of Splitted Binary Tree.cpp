/*
Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.

Since the answer may be too large, return it modulo 10^9 + 7.

1. Calculate the total sum of all nodes in the tree.
2. Calculate the left subtree sum and right subtree sum for each node.
3. Next, go thru each node and try removing left edge and find it the product and try removing right edge and find the product and keep track of maximum.


From @kaiwensun:

Overflow
For those who are not using Python and are worried about overflow:
You can use long int (which is 64-bit long)
Each tree has at most 50000 nodes and at least 2 nodes.
Each node's value is between [1, 10000].
So the maximum possible sum 5000 * 100000 = 500000000 = 0x1DCD6500 won't overflow 32-bit int.
500000000 * 500000000 won't overflow 64-bit long.
Mod
Don't do MOD too early when calculate the sum,
because that will give you wrong result when you look for the maximum value.


*/

#define MOD 1000000007;
class Solution {
public:
    long total=0;
    map<TreeNode*,pair<int,int>> mp;
    long ans = INT_MIN;
    int calSum(TreeNode* root)
    {
        total+=root->val;
        int lsum=0;
        int rsum=0;
        if(root->left)
            lsum=root->left->val+calSum(root->left);
        if(root->right)
            rsum=root->right->val+calSum(root->right);
        mp[root] = {lsum,rsum};
        return lsum+rsum;
    }
    void helper(TreeNode* root)
    {
        pair<int,int> pr = mp[root];
        long lsum = (total-pr.second) * pr.second;
        long rsum = (long long)(total-pr.first) * pr.first;
        ans = max(ans,max(lsum,rsum));
        if(root->left)
            helper(root->left);
        if(root->right)
            helper(root->right);
    }
    int maxProduct(TreeNode* root) 
    {
        if(!root)
            return 0;
        calSum(root);
        helper(root);
        return ans%MOD;
    }
};
