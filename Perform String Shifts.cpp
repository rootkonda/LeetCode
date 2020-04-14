/**
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

First try to sum all the consecutive operations of right shift or left shift and do it at once.
**/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int len = s.size();
        int left=0,right =0;
        int start;
        for(int i=0;i<shift.size();i++)
        {
            if(shift[i][0]==1)
            {
                right+=shift[i][1];
            }
            else if(right>0)
            {
                right%=len;
                start = len - right;
                string a = s.substr(start);
                string b = s.substr(0,start);
                s=(a+b);
                right = 0;
            }
            if(shift[i][0]==0)
            {
                left+=shift[i][1];
            }
            else if(left>0)
            {
                left%=len;
                string a = s.substr(0,left);
                string b = s.substr(left);
                s=(b+a);
                left = 0;
            } 
        }
        if(right>0)
        {
            right%=len;
            start = len - right;
            string a = s.substr(start);
            string b = s.substr(0,start);
            s=(a+b);
        }
        else if(left>0)
        {
            left%=len;
            string a = s.substr(0,left);
            string b = s.substr(left);
            s=(b+a);
        }
        
        return s;
    }
};
