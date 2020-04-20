/**
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)


1. For every element in the array, check if the next element is smaller. If it is smaller, then create a node for that element and recurse left with current value as parent.
2. Whenever next element is greater than current element, then stop there and return NULL. This is because, the greater element should be part of right subtree.

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
    int index = 0;
    TreeNode* BuildBST(vector<int>& preorder,int parent)
    {
        if(index == preorder.size() or preorder[index] > parent)
            return NULL;
        int current_value = preorder[index++];
        TreeNode* temp = new TreeNode(current_value);
        temp->left = BuildBST(preorder,current_value);
        temp->right = BuildBST(preorder,parent);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
          return BuildBST(preorder,INT_MAX);      
    }
};
