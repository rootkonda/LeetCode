/**
  Given two binary strings, return their sum (also a binary string).

  The input strings are both non-empty and contains only characters 1 or 0.
  
  Approach:
  
  Lengthy but striaght away binary addition. **/
  
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry=0;
        int i=a.length()-1;
        int j=b.length()-1;
        string res="";
        while(i>-1 and j>-1)
        {
            if(a[i]=='1' and b[j]=='1')
            {
                if(carry)
                  res='1'+res;
                else
                  res='0'+res;
                carry=1;
            }
            else if(a[i]=='1' or b[j]=='1')
            {
                if(carry)
                {
                    res='0'+res;
                    carry=1;
                }
                else
                {
                    res='1'+res;
                    carry=0;
                }
            }
            else if(carry)
            {
                res='1'+res;
                carry=0;
            }
            else
                res='0'+res;
               
            i--;
            j--;
        }
        while(i>-1)
        {
            if(a[i]=='1')
            {
                if(carry)
                  res='0'+res;
                else
                {
                   res=a[i]+res;
                   carry=0;
                }
                i--;
                continue;
            }
            if(carry)
                res='1'+res;
            else
                res='0'+res;
            carry=0;
            i--;
        }
        while(j>-1)
        {
            if(b[j]=='1')
            {
                if(carry)
                  res='0'+res;
                else
                {
                   res=b[j]+res;
                   carry=0;
                }
                j--;
                continue;
            }
            if(carry)
                res='1'+res;
            else
                res='0'+res;
            carry=0;
            j--;
        }
        if(carry)
            res='1'+res;
        return res;
    }
};
