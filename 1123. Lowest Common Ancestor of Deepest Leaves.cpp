/*
Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.

Constraints:

The given tree will have between 1 and 1000 nodes.
Each node of the tree will have a distinct value between 1 and 1000.


For a given node whenever the left depth and right depth are same then that node is our ancestor only when the left or right depth is greater than or equal to overall_depth when both left and right depths are equal. If left and right depths are different then just check which one is greater than overall_depth and assign that as our answer. Note that when left and right depths are not same then we should only check if one of them is STRICTLY greater than overall_depth. This is because when one of the depths is NULL then we should maintain the leaf node as our answer and if we use >= for our comparison then it will give us the ancestor as the parent node when one of the children is NULL.

*/

class Solution {
public:
    TreeNode* ans=NULL;
    int overall_depth=0;
    int helper(TreeNode* root,int currDepth)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL and root->right==NULL)
            return currDepth;
        int left=-1,right=-2;
        if(root->left)
            left = helper(root->left,currDepth+1);
        if(root->right)
            right = helper(root->right,currDepth+1);
        
        if(left==right and left>=overall_depth)
            ans = root;
        else if(left>overall_depth)
            ans = root->left;
        else if(right>overall_depth)
            ans = root->right;

        if(left>overall_depth)
            overall_depth=left;
        else if(right>overall_depth)
            overall_depth=right;
        if(left>0 and left>right)
            return left;
        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        if(root->left==NULL and root->right==NULL)
            return root;
        helper(root,0);
        return ans;    
    }
};

/*
[1,2,3,4,5]
[1,2,3,4,5,7]
[1,2,3,4]
[1,2,3]
[1,2,3,4,null,7,null,null,null,8]
[1,2,3,4,5,6,7,8,9,10,11]
[1]
*/
