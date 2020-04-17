/**

Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.

Standard Prefix Sum Technique works for XOR's also.

Example:
// 0 xor 4 = 4
// 4 xor 8 = 12
// 12 xor 2 = 14
// 14 xor 10 = 4

// 4 12 14 4
    
// 0 xor 1 = 1
// 1 xor 3 = 2
// 2 xor 4 = 6
// 6 xor 8 = 14

// 1 2 6 14

// 2 7 14 8

**/



class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> pref;
        vector<int> ans;
        int a,b;
        pref.push_back(arr[0]);
        
        for(int i=1;i<arr.size();i++)
            pref.push_back(pref.back()^arr[i]);
        
        for(auto q : queries)
        {
            if(q[0]!=q[1] and q[0]!=0)
                ans.push_back(pref[q[1]]^pref[q[0]-1]);
            else if(q[0]==0)
                ans.push_back(pref[q[1]]);
            else if(q[0]==q[1])
                ans.push_back(arr[q[0]]);
        }
        return ans;
    }
};

