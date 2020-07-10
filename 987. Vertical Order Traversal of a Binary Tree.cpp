/*



Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position (which stands for X, Y co-ordinate, not things in the same vertical line i.e. X coordinate only as you're interpreting), then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate. Every report will have a list of values of nodes.

The question is asking for things ordered in the manner of:

sorted by x co-ordinate first
sorted by y co-ordinate if x is same (decreasing)
sorted by value if x and y is same

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/231266/C%2B%2B-Well-Commented-Solution-(With-Explanation)-(100)-Level-Order-Traversal


1. queue to traverse level by level and prepare a map to have x and y coordinates with their corresponding values.
2. map is used to store all node values at every horizontal level along with their varying vertical points and its values.
3. We have to print the output sorted by x coordinates and use the above logic.

*/

class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b)
    {
        return (a.first!=b.first) ? a.first>b.first : a.second<b.second;
        /*
        sorted by x co-ordinate first
        sorted by y co-ordinate if x is same (decreasing)
        sorted by value if x and y is same
        */
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,pair<int,int>>> que; 
        map<int,vector<pair<int,int>>> mp;
        int x,y,index;
        x=y=index=0;
        que.push({root,{0,0}});
        while(!que.empty())
        {
            TreeNode* curr = que.front().first;
            x = que.front().second.first;
            y = que.front().second.second;
            que.pop();
            mp[x].push_back({y,curr->val});
            if(curr->left)
                que.push({curr->left,{x-1,y-1}});
            if(curr->right)
                que.push({curr->right,{x+1,y-1}});
        }
        ans.resize(mp.size());
        for(auto itr : mp)
        {
            vector<pair<int,int>> vec = itr.second;
            sort(vec.begin(),vec.end(),cmp);
            for(auto pr : vec)
                ans[index].push_back(pr.second);
            index++; //For each horizontal line
        }
        return ans;
    }
};

/*
[3,9,20,null,null,15,7]
[1,2,3,4,5,6,7]
*/
