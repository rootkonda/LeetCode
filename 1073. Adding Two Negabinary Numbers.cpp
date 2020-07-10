/*
Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.
Note:

1 <= arr1.length <= 1000
1 <= arr2.length <= 1000
arr1 and arr2 have no leading zeros
arr1[i] is 0 or 1
arr2[i] is 0 or 1

https://en.wikipedia.org/wiki/Negative_base#Addition
Carry can be 1 or 0 or -1
sum%2 = 2%-2 = -1
sum%2 = 3%-2 = -1
sum<0 then 1
*/
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> ans;
        int carry=0;
        int sz=max(arr1.size(),arr2.size());
        for(auto bit=0;bit<sz or carry!=0;bit++)
        {
            auto b1 = bit<arr1.size() ? arr1[arr1.size()-1-bit] : 0;
            auto b2 = bit<arr2.size() ? arr2[arr2.size()-1-bit] : 0;
            int sum = b1+b2+carry;
            ans.insert(ans.begin(),abs(sum)%2);
            carry = (sum<0) ? 1 : (sum>1) ? -1 : 0;
        }
        while(ans.size()>1 and ans[0]==0)
            ans.erase(ans.begin());
        return ans;
    }
};
