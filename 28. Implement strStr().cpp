/**
  Implement strStr().

  Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
  
  Approach:
  
  Get the substring of needle length from haystack and start the comparison. Each comparison with needle will be a substring
  of haystack starting from index 0. Repeat the process until there is a match or out of chars. 
  Example: substring of haystack from 0-needle.length(), next 1-needle.length() and so on. **/
  
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int nlen=needle.length();
        int hlen=haystack.length();
        if(nlen==0) 
            return 0;
        else if(nlen>hlen) 
            return -1;
        
        string s(haystack.substr(0, nlen));
        if(s.compare(needle)==0) 
            return 0;
        
        for(int i=s.length(); i<hlen; i++)
        {
            s = s.substr(1, nlen-1) + haystack[i];
            if(s.compare(needle)==0) 
                return i-s.length()+1;
        }
        
        return -1;
    }
};
