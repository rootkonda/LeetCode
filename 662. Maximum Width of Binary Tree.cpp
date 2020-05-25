/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.


Explanation
-----------
1.In general, when binary tree is represented in array we traverse to left and right using 2n and 2n+1 where n is the position of current element.

2.We use same idea, for every node we encounter we store its position in that level and also maintain prev and curr variables, containing left most node's rank/position and right most node's rank/position.

3.Finally when we are done processing all nodes at a given level and we got our left and right most nodes positions set to prev and curr then we find the width as (curr-prev+1) after each level. Since we have many levels, we have to keep maintaining the max answer after each level.

*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,double>> que; // using double because of a test case where it crosses limit of long long for levels more than 32
        double ans = 0;
        if(root==NULL)
            return ans;
        
        que.push({root,1}); 
        while(!que.empty())
        {// level-order traversal
            int n = (int)que.size();
            double prev = 0;
            double curr = 0;
            while(n--)
            {
                pair<TreeNode*,double> temp = que.front();
                curr = temp.second;
                que.pop();
                if(temp.first->left!=NULL)
                    que.push({temp.first->left,2*temp.second-1});
                if(temp.first->right!=NULL)
                    que.push({temp.first->right,2*temp.second});
                if(prev==0) // For the first node in the queue, there is no prev so prev will be curr.
                    prev = curr;
            }
            ans = max(ans,curr-prev+1);
        }
        return ans;
    }
};
