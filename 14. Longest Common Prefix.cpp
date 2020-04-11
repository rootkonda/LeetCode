/**
  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

  Approach:
  
  Intialize prefix as first string and start comparing from second string. 
  For each iteration, compare the length of current prefix and current string. Next, run the loop upto the smallest length.
  Get the new prefix and continue till the last string. **/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix=(strs.size()>0 ? strs[0] : "");
        
        for(int i=1;i<strs.size();i++)
        {
            string temp=strs[i];
            int len=prefix.length();
            string curr="";
            if(prefix.length()>temp.length())
                len=temp.length();
            
            for(int j=0;j<len;j++)
            {
                if(prefix[j]==temp[j])
                    curr+=prefix[j];
                else
                    break;
            }
            prefix=curr;
        }
        return prefix;
    }
};
