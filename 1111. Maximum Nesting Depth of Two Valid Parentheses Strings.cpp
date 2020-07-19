/*


Some observations
This problem uses very abstract and non-intuitive language; this is not a bad thing, just makes it hard to understand for those of us who are not well versed in that particular language.
The problem uses seemingly ambiguous language, when overloading the meaning of A and B: It first talks about A and B in the context of the definition of a VPS, but then re-defines A and B later as two disjoint subsequences in the solution of the problem, absolutely unrelated to the first definition.
After looking at some explanations and code samples, I see that the solution depends on whether or not the depth of a parenthesis is odd or not, but I did not get why, so I kept on pondering...
First things first: What is a VPS?
A VPS (or "valid parentheses string") is just a string containing balanced parentheses, i.e. any opening parenthesis is followed by exactly one that closes it, and any closing parenthesis is preceded by at least one unbalanced opening parenthesis.

Valid examples: ((())), (())(), ()((((((()))))))()()()() etc.

Invalid examples: )(, )), (())())) etc.

Now, what does this problem really want from me?
We are trying to minimize depth of a VPS by splitting all pairs of parentheses into two groups A and B. A and B can be any disjoint sub-sequence of the input sequence, as long as they are still VPS without changing the order of anything (side-note: the order constrained is implied by the word sequence).

Some examples:

"(())" can be grouped into A = "()" and B = "()" or, A = "" and B = "(())", but, for example, not A = "((" and B = "))" as those are not VPS
"(())()" can be grouped into A = "(())" and B = "()", and many other ways
However, the goal is to minimize the max depth of both groups.

In the last example ("(())()"), the grouping (A = "(())" and B = "()") is not minimal, because A has a max-depth of 2 while there exists a grouping where both only have a depth of 1, namely: A = ()() and B = (), or to visualize the designation:

parentheses =   [ (, (, ), ), (, )]
depths =        [ 1, 2, 2, 1, 1, 1 ]
groups =        [ A, B, B, A, A, A]
solution =      [ 0, 1, 1, 0, 0, 0]
NOTE: One of several other solutions would be: [1, 0, 0, 1, 0, 0], as A and B maintain a max depth of 1. Solutions are not unique.

Going deeper: How to minimize the depth?
This optimization problem does not really care too much about anything but the most deeply nested subset. For example, in the previous example that deepest stack would be (()). The remaining () we can put either in A or B (because, as it turns out they will have a depth of at most (roughly) maxDepth/2, so we don't care whether they are in A or in B; explained later).

So, as long as we fix the most deeply nested parentheses, we are all good.

Given a tall, but simple stack of parentheses, such as ((((((((())))))))), how do we split it into two disjoint sub-sequences that happen to be VPS, while also minimizing each of their depth?

Since we can only split them into two groups, the minimum depth we can achieve will always be ceil(maxDepth/2) and we achieve it by putting one half in each group. Trying to put less than half in one of the two groups, will leave the other group with more than one half.

Any other stack, we can handle using the same strategy, making sure that no other parenthesis will increase the max depth.

Interesting side note: Any stack in the sequence that is of max depth less or equal to ceil(globalMaxDepth/2) (of the entire sequence) we can assign any which way we want (as long as we maintain the VPS property), since they cannot increase the max depth of the resulting split.
E.g.: when looking at "((()))()()()()", we just gotta take good care of the first "((()))", then we can assign each following parenthesis pair "()" to A or B any which way we want, since their max depth is less or equal to ceil(3/2) = 2.

Solution
So what we need is a strategy to cut any stack in half while making sure that the resulting half-stacks are balanced VPS. There is many ways of doing it, but one of the easiest (and seemingly a very common) approach is by going for an odd/even strategy:

Get the depth at every index of the string
Put all odd-depth parentheses in one group, and all even-depth in the other
Done.
NOTE: Using this solution, parentheses at the same depth are always in the same group, so you can ensure that the resulting groups are balanced VPS.
*/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        int depth=0;
        vector<int> ans;
        for(auto c : seq)
        {
            if(c=='(')
                depth++;
            ans.push_back(depth%2);
            if(c==')')
                depth--;
        }
        return ans;
    }
};
