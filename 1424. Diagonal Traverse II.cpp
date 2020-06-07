/*
Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.

So if we have all elements with same sum of their indices together, then it’s just a matter of printing those elements in order.

Algorithm

Insert all elements into an appropriate bucket i.e. nums[i][j] in (i+j)th bucket.
For each bucket starting from 0 to max, print all elements in the bucket.
Note: Here, diagonals are from bottom to top, but we traversed the input matrix from first row to last row. Hence we need to print the elements in reverse order.

https://leetcode.com/problems/diagonal-traverse-ii/discuss/597741/Clean-Simple-Easiest-Explanation-with-a-picture-and-code-with-comments
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        int m=nums.size();
        int maxsum=INT_MIN;
        vector<vector<int>> sums;
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                if(sums.size()<=(i+j))
                    sums.push_back({nums[i][j]});
                else
                    sums[i+j].push_back(nums[i][j]);
                maxsum=max(maxsum,i+j);
            }
        }
        for(int i=0;i<=maxsum;i++)
        {
            for(int j=sums[i].size()-1;j>=0;j--)
                ans.push_back(sums[i][j]);
        }
        return ans;
    }
};

/*
[[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
[[1,2,3],[4,5,6],[7,8,9]]
[[1,2,3],[4],[5,6,7],[8],[9,10,11]]
[[1,2,3,4,5,6]]
[[14,12,19,16,9],[13,14,15,8,11],[11,13,1]]

*/
