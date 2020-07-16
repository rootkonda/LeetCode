

/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.
*/

class Solution {
public:
    vector<vector<TreeNode*>> dp;
    vector<TreeNode*> helper(int N)
    {
        vector<TreeNode*> res;
        if(dp[N].size()) // If N is already visited then return the vector we got at that time.
            return dp[N];
        if(N==1)
            res.push_back(new TreeNode());
        for(int i=1;i<N;i+=2) // i+=2 because i should always be odd number. When 3 is 1 this main loop executes only once.
        {
            int l=i,r=N-i-1; // N-i-1 gives the remaining nodes excluding parent node and left node so if N is 3 then l=1 and r=1 and remaining 1 is for parent.
            for(auto left : helper(l)) // list of all possible left subtrees
            {
                for(auto right : helper(r))//. list of all possible right subtrees
                {
                    TreeNode* node = new TreeNode(); // Create a parent node and assign the left and right subtrees to this and add it to the vector.
                    node->left=left;
                    node->right=right;
                    res.push_back(node);
                }
            }
        }
        return dp[N]=res; // since it is a recursion add the resultant vector of nodes to dp for later use when N repeats again. This is memoization
    }
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        if(N%2==0) // All even numbers cannot form a full binary tree so just return empty vector
            return {};
        dp.resize(21,{});
        helper(N); 
        return dp[N];
    }
};
