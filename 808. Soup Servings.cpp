/*
There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:

Serve 100 ml of soup A and 0 ml of soup B
Serve 75 ml of soup A and 25 ml of soup B
Serve 50 ml of soup A and 50 ml of soup B
Serve 25 ml of soup A and 75 ml of soup B
When we serve some soup, we give it to someone and we no longer have it.  Each turn, we will choose from the four operations with equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as we can.  We stop once we no longer have some quantity of both types of soup.

Note that we do not have the operation where all 100 ml's of soup B are used first.  

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time.
*/

class Solution {
public:
    vector<vector<int>> dir{{-4,0},{-3,-1},{-2,-2},{-1,-3}}; // Kinds of operations given
    double soupServings(int N) 
    {
        N = ceil(N/25.0); // divide by 25ml so we know how many parts of 25ml are there
        if(N > 500) return 1.0; // Probability is very close to 1 so return 1
        vector<vector<double>> dp(N+1,vector<double>(N+1,0));
        for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<N+1;j++)
            {
                if(i==0 and j>0) // A is empty and B has left over, probability is 1
                    dp[i][j] = 1.0;
                else if(i==0 and j==0) // A is empty and B is also empty at the same time, probability is 1 and 1/2 = 0.5 as given
                    dp[i][j] = 0.5;
                else if(i>0 and j>0) // When both A and B is not empty, we have to calculate the probability for each kind of operation.
                {
                    for(auto ab : dir)
                        dp[i][j]+=(0.25*dp[max(0,i+ab[0])][max(0,j+ab[1])]);
                }
            }
        }
        return dp[N][N];
    }
};
