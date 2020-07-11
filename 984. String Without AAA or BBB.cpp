/*


If the initial number of As is greater than Bs, we swap A and B.
For each turn, we add 'a' to our string.
If the number of remaining As is greater than Bs, we add one more 'a'.
Finally, we add 'b'.


*/


class Solution {
public:
    string strWithout3a3b(int A, int B,char a='a',char b='b',string res="") 
    {
        if(B>A)
            return strWithout3a3b(B,A,b,a);
        
        while(A-->0)
        {
            res+=a;
            if(A>B)
                res+=a,A--;
            if(B-->0)
                res+=b;
        }
        return res;
    }
};
