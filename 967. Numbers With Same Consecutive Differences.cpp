/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.
*/


class Solution {
public:
    vector<int> ans;
    void helper(int val,int N,int K)
    {
        if(N==0)
        {
          ans.push_back(val);
          return;
        }
        int d = val%10; //Take the unit digit
        val = val*10+d; //keep adding the unit digit to the value, starting from 10+1,10+2 etc which comes from caller method. Remember we have to find the difference between consecutive digits.So take the unit digit and find next digit either by d+k or d-k. val-k or val+k is because val has latest unit digit. Repeat this until N becomes 0.
        if(d-K>=0)
            helper(val-K,N-1,K); // 
        if(K and d+K<=9)
            helper(val+K,N-1,K);
    }
    
    vector<int> numsSameConsecDiff(int N, int K) 
    {
        int start = (N==1 ? 0 : 1); // When N=1 digit, then we have to just add all digits 0-9, otherwise digits start from from 1 to 9 ie >=10
        for(int i=start;i<=9;i++)
            helper(i,N-1,K);//N-1 because by default val is 10,which is two digits by itself so already N-1 for all N>1 digits
        return ans;
    }
};
