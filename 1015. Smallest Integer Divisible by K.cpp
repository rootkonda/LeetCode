/*

Given a positive integer K, you need find the smallest positive integer N such that N is divisible by K, and N only contains the digit 1.

Return the length of N.  If there is no such N, return -1.
1 <= K <= 10^5

Key idea here is that whenever the remainders are repeated then we detect a loop so return -1. This is impelmented as follows.

Run a loop from 1 till we get unique remainders and break the loop when we get repeated remainders.
Finally check if remainder zero exists in the list of remainders and return the size of set,which contains remainders. Or We can keep track of the count of unique remainders.

we don't need to use long long for a new number. Instead we just carry the remainder we get everytime doing %K and this is same as taking the entire number and doing %K.

*/


class Solution {
public:
    int smallestRepunitDivByK(int K,int ans=0) 
    {
        vector<int> vis(K,0);
        for(int num=1;!vis[num%K];num = ((num*10)+1)%K,ans++)
            vis[num%K]=1;
        return (!vis[0] ? -1 : ans);
    }
};


