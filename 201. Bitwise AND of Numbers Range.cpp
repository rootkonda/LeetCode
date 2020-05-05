/**
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/592288/100-memory!-C%2B%2B-solution-with-explanation
**/

public:
    int rangeBitwiseAnd(int m, int n) {
         int count=0;
       // simple solution is to do bitwise and and return the sum. 
      //     for(int i=m;i<=n;i++)
      //               sum&=i;        
		 //      return sum;
        while(m!=n)  // see till both numbers are equal
        {   // right shift both numbers by 1
            m>>=1; 
            n>>=1;
            count++;  // increment the count.
        }
		//count gives the number of zero places from the lsb so left shift m by count.
        return m<<count;
    }
