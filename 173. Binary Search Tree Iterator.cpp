/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

https://leetcode.com/problems/binary-search-tree-iterator/discuss/52647/Nice-Comparison-(and-short-Solution)
*/
class BSTIterator {
public:
    private: 
        TreeNode* visit;
        stack<TreeNode*> stack;
    public:
        BSTIterator(TreeNode* root) {
            visit = root;
        }

        bool hasNext() {
            return visit != NULL || !stack.empty();
        }

        int next() {
            while (visit != NULL) {
                stack.push(visit);
                visit = visit->left;
            }
            TreeNode* nxt = stack.top();
            stack.pop();
            visit = nxt->right;
            return nxt->val;
        }
};
