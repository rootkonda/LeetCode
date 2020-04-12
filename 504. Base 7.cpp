/**
Given an integer, return its base 7 string representation.
Note: The input will be in range of [-1e7, 1e7].

Repeat n mod by 7 until n becomes zero.
**/

class Solution {
public:
    string convertToBase7(int num) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        string ans="";
        if(num==0)
            return to_string(num);
        int n=num;
        if(num<0)
            num=-num;
        while(num!=0)
        {
            ans=to_string((num%7))+ans;
            num/=7;
        }
        if(n<0)
            return "-"+ans;
        return ans;
    }
};
