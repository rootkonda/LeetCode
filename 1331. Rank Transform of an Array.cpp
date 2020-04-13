/**
Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.

1. Prepare vector of pairs.
2. Sort them and assign ranks.

**/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int len=arr.size();
        if(len==0)
            return arr;
        vector<pair<int,int>> a;
        for(int i=0;i<len;i++)
            a.push_back(make_pair(arr[i],i));
        
        sort(a.begin(),a.end());
        int rank=1;
        int ans[len];
        memset(ans,1,sizeof(ans));
        for(int i=1;i<len;i++)
        {
            if(a[i-1].first==a[i].first)
                ans[a[i].second]=ans[a[i-1].second];
            else
                ans[a[i].second]=++rank;
        }
        
        return vector<int>(std::begin(ans), std::end(ans));
    }
};
