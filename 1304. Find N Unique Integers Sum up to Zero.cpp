/**
Given an integer n, return any array containing n unique integers such that they add up to 0.

If n is odd, add 0 and do n--.
Loop thru and keep adding +i and -i both numbers.

**/

class Solution 
{
public:
    vector<int> sumZero(int n) 
    {
        vector<int> res;
        if(n==1)
        {
            res.push_back(0);
            return res;
        }
        if(n%2!=0)
        {
            res.push_back(0);
            n--;
        }
        int mul=1;
        for(int i=1;i<=n;i++)
        {
            if(mul==1)
                res.push_back(i);
            else
                res.push_back(res.back()*mul);
            mul*=-1;
        }   
        return res;
    }
};

