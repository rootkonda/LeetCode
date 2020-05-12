/*
We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

Reference:
https://medium.com/brain-framework/longest-well-performing-interval-93026a88a44b
For each index i, inorder for Subarrays (start, i) to be well-performing, we need: prefix[i]-prefix[start-1] > 0 (Ignore edge case start=0 for the moment).
So the subarrays (start, i) that verify prefix[start-1]<prefix[i] are the well performing subarrays that end in i.
For the example above, when we are at the third 9 (prefix = 0) we consider indices that have prefix < 0, so typically here prefix=-1 and prefix=-2, and we take the most left index (which is in this case the index 0). We then update res = max(res, i-mostLeftIndex).
Because before -2 there is necessarily an occurence of -1(initially we have a difference of 0 and we always increment or decrement by 1), for prefix[i]=0, we just focus on starting cells having -1 (prefix[i]-1) as value. And because we want the smallest index we just focus on its first occurence.
To sum up, for each index i we want the index of the first occurence of prefix[i]-1. A hashtable storing prefixes as key and their first occurence as value will help us take O(1) time for each iteration.
Now for the edge case of subarray starting from 0:
*/

class Solution {
public:
    int longestWPI(vector<int>& hours) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<int,int> first;
        int ans = 0;
        int pref = 0;
        for(int i=0;i<(int)hours.size();i++)
        {
            pref=(hours[i] > 8 ? pref+1 : pref-1);
            if(pref>0)
                ans = i+1;
            else if(first.find(pref-1)!=first.end())
                ans = max(ans,i-first[pref-1]);
            
            if(first.find(pref)==first.end())
                first[pref] = i;
        }
        return ans;
    }
};

//-1 0 -1 0 -1

