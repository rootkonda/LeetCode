/**
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Simple and straightforward.
**/

class Solution 
{
public:
    int countSegments(string s) 
    {
        vector<string> ans;
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' and temp.length()>0)
            {
                ans.push_back(temp);
                temp="";
            }
            else if(s[i]!=' ')
                temp+=s[i];
        }
        if(temp.length()>0)
            return ans.size()+1;
        
        return ans.size();
                    
    }
};
