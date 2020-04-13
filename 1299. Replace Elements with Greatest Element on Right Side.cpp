/**
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

Start from the last element and set it to -1.
Update the maximum element with max(max,curr[i])
Every element set the max element.

**/

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n);
        int max = -1;
        for(int i=n-1; i>=0; i--){
            v[i] = max;
            if(arr[i]>max){max = arr[i];}
        }
        return v;
    }
};
