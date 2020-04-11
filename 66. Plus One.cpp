/**
  Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

  The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

  You may assume the integer does not contain any leading zero, except the number 0 itself.
  
  Approach:
  
  Start from last digit and add 1 to it. Calculate carry and if its there then run a loop on every digit from last and keep calculating
  carry and store the remainder of each sum at the digits place. **/
  

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry=0,sum;
        int len=digits.size();
        sum=(digits[len-1]+1);
        carry=sum/10;
        if(!carry)
            digits[len-1]=sum;
        else
        {
            int i=len-2;
            digits[len-1]=sum%10;
            while(i>=0)
            {
                sum=(digits[i]+carry);
                carry=sum/10;
                digits[i--]=sum%10;
            }   
        }
        if(carry)
            digits.insert(digits.begin(),carry);
        return digits;
    }
};
