/*
Given a list of non negative integers, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.


Using custom comparator. Convert the int array to string array. When we have a="121" and b = "12" when we try to find the largest number after concatenating, we have two ways to join them...a+b or b+a and see which one is bigger. Sort the array in descending order and just append it to the ans and return it. 
*/



class Solution {
public:
    static bool cmp(string a, string b)
    {
        return string(a+b)>string(b+a);
    }
    string largestNumber(vector<int>& nums) 
    {
        int n = nums.size();
        vector<string> strs(n);
        if(n==0)
            return "";
        for(int i=0;i<n;i++)
            strs[i] = to_string(nums[i]);   
        
        sort(strs.begin(),strs.end(),cmp);
        string ans ="";
        for(int i=0;i<n;i++)
            ans+=strs[i];
        
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};
