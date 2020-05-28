/*
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

Generate all possible sums for a given weight. i.e. For each weight add +wgt and -wgt to previous possible sums and repeat this until the last stone. Finally take the absolute minimum value as the answer. Use hashing to avoid duplicates.
*/


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        unordered_set<int> sums = {0};
        for(auto wgt : stones)
        {
            unordered_set<int>  temp;
            for(auto sum : sums)
                temp.insert({sum+wgt,sum-wgt});
            sums = temp;
        }
        int ans = INT_MAX;
        for(auto sum : sums)
            ans = min(ans,abs(sum));
        return ans;
    }
};
