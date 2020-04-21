/**
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
**/


class Solution {
public:
    vector<int> countBits(int num) 
    {
        int next_pow_of_two = 2;
        int prev_pow_of_two;
        vector<int> ans(num+1);
        ans[0] = 0;
        for(int i=1;i<=num;i++)
        {
            if(i%2==0)
                ans[i] = ans[i/2];
            else
                ans[i] = ans[i-1]+1;
        }
        return ans;
    }
};
