/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.


*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n = (int)nums.size();
        if(n<2)
            return nums;
        vector<int> div(n,0); // To store the length of largest subset possible at a given index i
        vector<int> parent(n,0); // To store the parent index from which the current index's length came.
        vector<int> ans;
        int index = -1;
        int mx = INT_MIN; // Keeps track of maxmimum
        sort(nums.begin(),nums.end()); 
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(nums[j]%nums[i]==0 and div[i]<1+div[j])
                {
                    div[i] = 1+div[j];
                    parent[i] = j; // For Backtracing the elements to form the answer
                    if(div[i]>mx) // Current length is bigger than the max length seen so far
                    {
                        mx = div[i]; // Update the max length
                        index = i; // Keep a note of index at which the length is maximum
                    }
                }
            }
        }
        
        for(int i=0;i<mx;i++)
        {
            ans.push_back(nums[index]);
            index = parent[index]; // Starting with maximum length, we traverse thru its chain "maximum length" times
        }
        return ans;
    }
};
