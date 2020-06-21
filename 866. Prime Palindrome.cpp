/*

If the number of digits of a palindromic prime is even,then the sum of digits on the odd digits must be equal to the sum of the digits on the even digits. According to the divisibility theory of numbers, it is certain that such a number can be divisible by 11, so it can't be prime. In fact, except for 11, all palindromic prime have odd Numbers of digits

*/


class Solution {
public:
    int check(int n)
    {
        int ans=0;
        while(n)
        {
            ans = 10* ans+(n%10);
            n/=10;
        }
        return ans; // reversing the given n
    }
    inline bool isPrime(int n)
    {
        if((n&1)==0) // If n is even number the n&1 will be 0
            return n==2; // 2 is the only even prime number so except 2 rest of numbers return false;
        for(int i=3;i<=sqrt(n);i+=2) // Check if any number from 3 to sqrt(n) is dividing n
        {
            if(n%i==0)
                return false;
        }
        return n>1; // to return false when n is 1.
    }
    int primePalindrome(int N) 
    {
        while(true)
        {
            if(N==check(N) and isPrime(N)) // First check if N is palindrome and then check for prime in that order. This is to save time as isPrime is expensive.
                break;
            N++;
            if (10000000 < N && N < 100000000) // All 8 digit numbers are not prime so check if N is greater than minimum 7 digit number and less than minimum 9 digit number. This means N is 8 digit number. So set the N to minimum 9 digit number 
                N = 100000000;
        }
        return N;
    }
};
