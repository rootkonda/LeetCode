/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

*/


class Solution {
public:
    unordered_map<int,int> sums;
    vector<int> ans;
    int high=INT_MIN;
    int helper(TreeNode* root)
    {
        if(root==NULL)
            return 0; // For leaf node
         // For each node, goto left and right and add those node's value to the current node's value
        int left=helper(root->left);
        int right=helper(root->right);
        int sum = left+right+root->val;
        sums[sum]++; // maintain the frequency for each sum
        if(sums[sum]>high)
            high=sums[sum]; // keep track of highest frequency
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        helper(root);
        for(auto itr : sums)
        {
            if(itr.second==high) //Whichever sum matches the highest frequency add that to answer.
                ans.push_back(itr.first);
        }
        return ans;
    }
};
