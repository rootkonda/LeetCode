/*
There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. Initially, all the bulbs are turned off.

At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. A bulb change color to blue only if it is on and all the previous bulbs (to the left) are turned on too.

Return the number of moments in which all turned on bulbs are blue.
If sum upto any index i is equal to n*(n+1)/2 from 1 to i+1 as n then it means we have all bulbs ON so increment the answer.
*/
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) 
    {
        int nsum=1;
        int inc=2;
        int sum=0;
        int ans=0;
        for(int i=0;i<light.size();i++)
        {
            sum+=light[i];
            if(sum==nsum)
                ans++;
            nsum+=inc;
            inc++;
        }
        return ans;
    }
};

/*
Solution - 2
-------------
Keep track of max value and check every time if max is i+1 it means we have collected all bulbs to the left.
https://leetcode.com/problems/bulb-switcher-iii/discuss/532538/JavaC%2B%2BPython-Straight-Forward-O(1)-Space
*/

int numTimesAllBlue(vector<int>& A) {
        int right = 0, res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            res += (right = max(right, A[i])) == i + 1;
        return res;
    }
