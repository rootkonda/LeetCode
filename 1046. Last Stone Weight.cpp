/**
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

Approach: Use priority-queue in this situation is more suitable. It stores the duplicates and also in either ascending or descending order.

**/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        priority_queue<int> rocks;
        for(auto s : stones)
            rocks.push(s);
        while(rocks.size()>1)
        {
            int y = rocks.top();
            rocks.pop();
            int x = rocks.top();
            rocks.pop();
            rocks.push(y-x);
        }
        return rocks.top();
    }
};
