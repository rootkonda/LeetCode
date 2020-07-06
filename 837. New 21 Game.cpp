
/*
Explanation:

This question takes me a while to understand what this means.

After struggled for a while, I would like to post how I understand if you are confused about what happened even after reading some of the solutions posted here.

Take one example first:

N = 12, W = 10, K = 10

The stop range for the game is [10, 10 + 10 -1] which is [K, K + W -1]

dp[i] means if the target K is set to this one what is the possiblty to be <=N

For i <= W
dp[0] = 1.0 for sure

dp[1] = 1.0 / W because one of W chance we get 1

dp[2] = dp[1] / W + 1 / W we have 2 ways to get 2 here, 1 + 1 and 0 + 2

dp[3] = dp[2] / W + 1 / W

and so on, we can see this is a GP until i reach W, so dp[i] = (dp[i-1] + 1.0) / 2

To reach value i which is bigger than W, you must start from some previous value i in range [i - w, i - 1], so the possibilty smaller than that is not possible

For example i = 11, previous value range is [1, 10], but there is no such part of 1/W because no value of single draw can be > W, so we don't do the addition here. Instead, we need to reduce the change of value 1 after move to next value

dp[11] = dp[1] + dp[2] ... + dp[10]

dp[12] = dp[2] + d[3] ... + dp[10] - We have to remove dp[1] because dp[12] should be sum of last W values.

Everytime we move to the next, get rid of the leftmost value.

The function stops at reach N.

Here we use a Wsum to carry the sum to the next dp everytime.

And the values end in range
[10, min(10 + 10 -1, N)] will be the result
*/

class Solution {

    public double new21Game(int N, int K, int W) {
        //After K points Alice is going to stop the game
        
       /**
            if N >= K - 1 + W, probability is 1
            Reason: let's say Alice lands on K - 1 Points and then draw a next card, 
                    let assume that card is of maximum value W 
                    so max point Alice can get at any point will be K - 1 + W
                    if N is greater than that probablity will always be 1
       */
        if(N >= K - 1 + W || K == 0) return 1d;
        
        /**
            if N < K, probability is 0
            Reason: Alice will only stop after K points, and if K is greater than N 
                    Probablity that Alice draws total point of N or less than N will be 0
        */
        else if(N < K) return 0d;
        
        
        /**
            Now we have to find probablity that Alice will have N or less than N points 
            let's say dp[i] -> is probability that Alice have total of i points 
            so it becomes dp problem where ans is dp[0] + dp[1] + .... dp[N]
        */
        double[] dp = new double[N + 1];
        /**
            let's say we have W = 3 and K = 4 and N = 5, let's work on DP array
            
            let's assume probablity of getting 0 is 1
            
            => Probablity that alice get 1 is 1 / 3, so dp[1] = 1 / 3;
            Reason: Because we have 3 cards with face values of 1, 2 & 3. If Alice draw a single card randomly 
            probability that alice gets 1 is 1 / 3
            
            => Probablity that alice get 2 is 4 / 3, so dp[2] = 4 / 3
               probabilty(1) / 3 + probablity(0) / 3
               = 1 / 9 + 1 / 3
               = 4 / 3
             
            => Probablity that alice get 3 
               probablity(2) / 3 + probablity(1) / 3 + probablity(0) / 3
               = 4 / 9 + 1 / 9 + 1 / 3
               = 5 / 9 + 1 / 3
               = 16 / 9
        
            => Probablity that alice get 4 
               probablity(3) / 3 + probablity(2) / 3 + probablity(1) / 3
               = 16 / 27 + 4 / 9 + 1 / 9
               = 16 / 27 + 5 / 9
               = 16 / 27 + 15 / 27
               = 31 / 27
               - Notice here we are not adding probablity(0) / 3, 
                 Because we have cards with maximum face value of 3 so we can't have make 4 in a single draw
        */
        
        //let's assume probablity of getting 0 is 1
        dp[0] = 1;
        
        //Probablity that alice get 2 is probabilty(1) / 3 + probablity(0) / 3, so we maintain a variable probSum
        double probSum = 1;
        double res = 0;
        for(int i = 1; i <= N; i++) {
            dp[i] = probSum / W;
            if(i < K) probSum += dp[i];
            else res += dp[i];
            /**
                Probablity that alice get 4 
                = probablity(3) / 3 + probablity(2) / 3 + probablity(1) / 3
                
                - Notice here we are not adding probablity(0) / 3, 
                 Because we have cards with maximum face value of 3 so we can't have make 4 in a single draw
                 
                 so probSum -= dp[i - W]
            */
            if(i - W >= 0) probSum -= dp[i - W];
        }
        return res;
    }
}
