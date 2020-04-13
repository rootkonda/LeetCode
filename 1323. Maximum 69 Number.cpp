/**
Given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Simple.
**/

class Solution {
public:
    int maximum69Number (int num) 
    {
        string ans=to_string(num);
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]=='6')
            {
                ans[i]='9';
                return stoi(ans);
            }     
        }
        return num;
    }
};
