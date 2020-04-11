/** 
   Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
   
   Same as Reverse Integer problem. Just reverse the digits and compare the final value with given number. **/
class Solution {
public:
    bool isPalindrome(long long x) 
    {
        if(x<0)
            return false;
        
        long long temp=x/10;
        long long res=x%10;
        
        while(temp!=0)
        {
            res*=10;
            res+=(temp%10);
            temp/=10;
        }
        if(res==x)
            return true;
        return false;
    }
};
