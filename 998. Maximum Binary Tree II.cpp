/*
We are given the root node of a maximum tree: a tree where every node has a value greater than any other value in its subtree.

Just as in the previous problem, the given tree was constructed from an list A (root = Construct(A)) recursively with the following Construct(A) routine:

If A is empty, return null.
Otherwise, let A[i] be the largest element of A.  Create a root node with value A[i].
The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
The right child of root will be Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
Return root.
Note that we were not given A directly, only a root node root = Construct(A).

Suppose B is a copy of A with the value val appended to it.  It is guaranteed that B has unique values.

Return Construct(B).

Remember that the given value is appended to A list, so it means its added at the end. Hence we have to focus on right subtree.
If the current node value is smaller than given value then create a new node and current node will be the new node's left child. Or else keep traversing in the right subtree when the given value is lesser than the node's value
*/

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) 
    {
        if (root == nullptr || val > root->val) 
        {
            auto n = new TreeNode(val);
            n->left = root;
            return n;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
