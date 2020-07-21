/*

We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.

Sort all labels by value. Then, start with the largest value, greedily pick labels. Track how many labels we have used in m, and do not pick that label if we reached the limit.
Multiset is used because we want to store duplicate pairs in descending order because we want to find largest sum.
Everytime we include it in answer just make sure that label value in the map is less than the limit. Number of times the label is used should be less than the limit.
*/
class Solution {
public:
    int largestValsFromLabels(vector<int>& v, vector<int>& l, int sz, int limit) 
    {
        multiset<pair<int,int>,std::greater<pair<int,int>>> st;
        unordered_map<int,int> mp;
        for(int i=0;i<v.size();i++)
            st.insert({v[i],l[i]});
        int ans=0;
        for(auto itr : st)
        {
            if(!sz)
                break;
            if(++mp[itr.second]<=limit)
            {
                ans+=itr.first;
                --sz;
                
            }
        }
        return ans;
    }
};
