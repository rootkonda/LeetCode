/*

Explanation: The row of the DP vector represent the N number of hops. The column of the DP vector represent
the numeric phone pad keys [0:9] ( zero to nine, inclusive ). Then the DP formula is as follows:

Base case: when N is 1, the knight will take zero hops from its current digit

dp[1][0:9] = 1

Recursive case: observe the overlapping subproblems and optimal substructure. The current i-th hop for each keypad digit can be found from the previous i-th-minus-1 hop for each keypad digit which can reach the current keypad digit from a single hop. Therefore calculate the current i-th hop for each keypad destination digit (dst) as the sum of all keypad source digits (src) i-th-minus-1 hop solutions.

dp[ i ][ dst ] = sum( dp[ i-1 ][ src ] )


*/


class Solution {
public:
    static const int MOD = 1000000007;
    vector<vector<long>> hops{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
    int knightDialer(int N) 
    {
        vector<long> dp(10,1);
        while(--N>0)
        {
            vector<long> curr(10,0);
            for(int key=0;key<=9;key++)
            {
                for(auto hop : hops[key])
                    curr[key]+=dp[hop]%MOD; // In order to reach say curr[6] it can reach from 3 keys such as 0 1 7 so add the sum upto these keys to current key.
            }
            dp.swap(curr);
        }
        return accumulate(dp.begin(),dp.end(),0L)%MOD;
    }
};
