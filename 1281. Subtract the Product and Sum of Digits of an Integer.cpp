/**
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Just simple.
**/

class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int p=1,s=0,digit;
        while(n!=0)
        {
            digit=n%10;
            p*=digit;
            s+=digit;
            n/=10;
        }
        return p-s;
    }
};
