/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Note:
The size of the given array will be in the range [1,1000].


1. First prepare a MaxHeap to fetch the next maximum element.
2. For each max element, traverse the constructed tree and insert it in the appropriate position based position of this element
3. Map is used to maintain the connection between a node address and the element's position in the array.

*/


class Solution {
public:
    unordered_map<TreeNode*,int> pos;
    void traverse(TreeNode* root,pair<int,int> pr)
    {
        if(pos[root]<pr.second)
        {
            if(root->right)
                traverse(root->right,pr);
            else
            {
                root->right = new TreeNode(pr.first);
                pos[root->right] = pr.second;
                return;
            }
        }
        else if(pos[root]>pr.second)
        {
            if(root->left)
                traverse(root->left,pr);
            else
            {
                root->left = new TreeNode(pr.first);
                pos[root->left] = pr.second;
                return;
            }
        }
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        priority_queue<pair<int,int>> maxheap;
        
        for(int i=0;i<nums.size();i++)
            maxheap.push({nums[i],i});
        
        TreeNode* root = new TreeNode(maxheap.top().first);
        pos[root] = maxheap.top().second;
        maxheap.pop();
        while(!maxheap.empty())
        {
            pair<int,int> tmp = maxheap.top();
            maxheap.pop();
            traverse(root,tmp);
        }
        return root;
    }
};
