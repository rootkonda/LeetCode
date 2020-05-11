/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int size = T.size();
        vector<int> ans(size,0);
        deque<pair<int,int>> temperatures; // For efficient insertion at the front of the queue.
        
        for(int i=size-1;i>=0;i--) // Start from the back
        {
            while(!temperatures.empty() and T[i]>=temperatures.front().first)
                temperatures.pop_front();
            
            if(!temperatures.empty())
                ans[i]=temperatures.front().second-i; // index of the highest element minus the current index
            
            temperatures.push_front({T[i],i}); // push the current highest element to front of the queue.
        }
        return ans;
    }
};
    

