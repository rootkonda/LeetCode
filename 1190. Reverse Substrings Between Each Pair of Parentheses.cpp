/*

1. Keep a note of every '(' and ')' positions in both ways i.e. in ascending and descending order positions.
2. Next in a new loop, we start matching '(' or ')' and at the start we get characters from the end and d is -1 and next we see ')' and have +1 take characters from the beginning.
So it alternatively it goes from back and front.

*/
class Solution {
public:
    
    string reverseParentheses(string s) 
    {
        int n = s.size();
        vector<int> opened,pair(n);
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                opened.push_back(i);
            else if(s[i]==')')
            {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        for(int i=0,d=1;i<s.size();i+=d)
        {
            if(s[i]=='(' or s[i]==')')
                i = pair[i], d = -d;
            else
                ans+=s[i];
        }
        return ans;
    }
};
