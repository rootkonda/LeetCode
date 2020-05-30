/*


Given a binary tree root, a ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right then move to the right child of the current node otherwise move to the left child.
Change the direction from right to left or right to left.
Repeat the second and third step until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Explanation:
------------
1. For each node in the given tree, traverse its left and its right. For every left or right traversal we call helper method to do the zigzag for us. After every zigzag recursive call store the result of that node in a dp array with the direction we took and its result with it. Next time we find the same node then just return that instead of recursing again. Directions of left and right are -1 and 1 respectively.

2. Another way is just to use recursion all the way and at every recursive call we make two more recursive calls for left and right traversals. At any point, if we reach a leaf node, then update the max answer and return. Here there is no dp array.  This is nothing but DFS.
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/discuss/614941/SImple-REcursion-C%2B%2B

*/


class Solution {
public:
    int ans = 0;
    unordered_map<TreeNode*,pair<int,int>> dp;
    int helper(TreeNode* root,int dir)
    {
        if(dp.count(root)>0 and dp[root].first==dir)
            return dp[root].second;
        
        if(root==NULL)
            return 0;
        if(dir==-1)
        {
            int temp = 1+helper(root->right,1);
            dp[root].first = 1;
            dp[root].second = temp;
            return temp;
        }
        else
        {
            int temp = 1+helper(root->left,-1);
            dp[root].first = -1;
            dp[root].second = temp;
            return temp;
        }
    
        return 0;
    }
    void caller(TreeNode* root,int dir)
    {
        if(root==NULL)
            return;
        
        if(dp.count(root->right)==0 and dp[root].first!=dir)
            ans = max(ans,helper(root->right,1));
        
        caller(root->right,1);
        
        if(dp.count(root->left)==0 and dp[root].first!=dir)
            ans = max(ans,helper(root->left,-1));
        
        caller(root->left,-1);
    }
    int longestZigZag(TreeNode* root) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        caller(root,1);
        return ans;
    }
};
