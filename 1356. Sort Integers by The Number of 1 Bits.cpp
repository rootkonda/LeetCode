/**
Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the sorted array.

1. Calculating number of 1's can be done by using n%2.
2. Store the count and its integer into a vector of pairs.
3. Sort the vector of pairs.

**/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<pair<int,int>> bc(arr.size());
        vector<int> ans(arr.size());
        int count=0,n;
        for(int i=0;i<arr.size();i++)
        {
            n=arr[i];
            while(n!=0)
            {
                if(n%2==1)
                    count++;
                n/=2;
            }
            bc[i].first=count;
            bc[i].second=arr[i];
            count=0;
        }
        sort(bc.begin(),bc.end());
        for(int i=0;i<arr.size();i++)
            ans[i]=bc[i].second;
        
        return ans;
    }
};
