/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

1. Start from right to left.
2. Push each element into stack.
3. For each element check if stack is not empty and then keep popping stack elements until we find a greater element.
4. Once we find it, push the current index and also set this value in the ans.
5. Repeat the same once again to take care of circular condition, means we have compared all elements before and after the current element.
*/

class Solution {
public:
    void helper(stack<int>& stack,vector<int>& ans,vector<int>& nums)
    {
        int n = (int)nums.size();
        for(int k=n-1;k>=0;k--)
        {
            while(!stack.empty())
            {
                if(nums[k]<nums[stack.top()])
                {
                    ans[k] = nums[stack.top()];
                    stack.push(k);
                    break;
                }
                else
                    stack.pop();
            }
            if(stack.empty())
            {
                stack.push(k);
                ans[k] = -1;
            }
        }
    }
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = (int)nums.size();
        stack<int> stack;
        vector<int> ans(n);
        helper(stack,ans,nums);
        helper(stack,ans,nums);
        return ans;
    }
};

/*
10,4,5,6,11
-6 1 1 1 5
-2 -1

*/
