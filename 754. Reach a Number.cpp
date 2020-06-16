/*
You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Explanation
-----------
First Think It's Actually Nothing But An arithmetic Series sum as...........
target 4;

1+2+3=6 ( So, 4 is Over ) Now , just think that we can surely make this equation to form 4 by flipping 1 to (-1) , So then summation will be 6-(1+1)==4 , So, assumption is when we flip a number(here 1) then we have to subtract that number from the summation (here 6) twice( Here 6-(1+1)==4 ) . So , from here what we can observe that as for flipping we have to subtract twice of some number from summation. So, obviously we are subtracting even number ( Here we are flipping 1 , So we have to subtract (1+1) which is even from summation 6 ) and finally we can reach goal target 4.

Let's take another example (our target 5 ) ....

1+2+3+4+5=15;
if we flip 5 to (-5) , then what we can observe here ..... our now sum value will be 15-(5+5) =5, let's see this as series below ...
1+2+3+4-5=5;
Our traget has been reached , hasn't it ?
That means we have to search for when Our summation(15) will be over our target(5) where our difference(10) is even number , because to flip a number(5) from positive(+5) to negative(-5) we have to subtract twice(5+5) of that number ........

So , we will get our target step ,when our summation and target value difference is even number :)

I hope this is basic explanation ever .This is will Help U

https://leetcode.com/problems/reach-a-number/discuss/188999/Throw-Out-All-Fucking-Explanations-This-is-nice-explanation-(c%2B%2B)-I-think-.......
*/



class Solution {
public:
    int reachNumber(int target) 
    {
        target = (target<0) ? -target : target;
        int step=0;
        int sum=0;
        while(true)
        {
            ++step;
            sum+=step;
            if(sum==target)
                return step;
            else if(sum>target and (sum-target)%2==0)
                return step;
        }
        return 0;
    }
};
