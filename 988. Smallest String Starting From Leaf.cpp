/*

Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)


In this approach we form a string first and then use lexicographical_compare STL to keep track of lexicographically smallest string at all times. This is a top-down solution because bottom-up doesnt work for input like "ababz" and "abz". "ababz" is the smallest lexicographical string compared to "abz". 

In another appraoch, we can also take the minimum of two children and then use that to form a new string. If both are same, then don't include anything just return the current string.

https://leetcode.com/problems/smallest-string-starting-from-leaf/discuss/231102/C%2B%2B-3-lines
*/


class Solution {
public:
    string ans="";
    void get(TreeNode* root,string curr)
    {
        if(root->left==NULL and root->right==NULL)
        {
            if(!ans.empty())
            {
                if(lexicographical_compare(curr.begin(),curr.end(),ans.begin(),ans.end()))
                    ans = curr;
            }
            else
                ans = curr;
            return;
        }
        if(root->left!=NULL)
            get(root->left,string(1,('a'+root->left->val)).append(curr));
        if(root->right!=NULL)
            get(root->right,string(1,('a'+root->right->val)).append(curr));
    }
    string smallestFromLeaf(TreeNode* root) 
    {
        get(root,string(1,('a'+root->val)));
        return ans;
    }
};
