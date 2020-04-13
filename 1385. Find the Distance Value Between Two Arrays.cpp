/**
Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

Difference between 2 elements can be in a range from low to high.

**/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        set<int> st;
        int count=0;
        for(int i=0;i<arr2.size();i++)
            st.insert(arr2[i]);
        
        for(int i=0;i<arr1.size();i++)
        {
            
            int low=arr1[i]-d;
            int high=arr1[i]+d;
            auto itr=st.begin();
            for(;itr!=st.end();itr++)
            {
                if(*itr>=low and *itr<=high)
                    break;
            }
            if(itr==st.end())
                count++;
        }
        return count;
    }
};
