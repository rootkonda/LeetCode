/*
In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.

1. Count the duplicates of each number given in array.
2. Push the count into priority queue, which maintains the maximum value at the top (max heap)
3. Start inserting the number from 0 and subsequent even position and whenever index is greater than n then we can reset it to 1(odd position)
4. So the idea is Even positions first and then odd positions.

*/
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bc) 
    {
        int n = bc.size();
        vector<int> ans(n);
        unordered_map<int,int> mp;
        for(auto num : bc)
            mp[num]++;
        priority_queue<pair<int,int>> pq;
        for(auto it : mp)
            pq.push({it.second,it.first});
        
        int idx=0;
        while(!pq.empty())
        {
            pair<int,int> pr = pq.top();
            pq.pop();
            for(int i=0;i<pr.first;i++)
            {
                ans[idx] = pr.second;
                idx+=2;
                if(idx>=n)
                    idx=1;
            }
            
        }
        return ans;
    }
};
