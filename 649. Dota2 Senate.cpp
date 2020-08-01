/*

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the senate wants to make a decision about a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right:
A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory:
If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and make the decision about the change in the game.
 

Given a string representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party respectively. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party, you need to predict which party will finally announce the victory and make the change in the Dota2 game. The output should be Radiant or Dire.

Explanation:

This is obliviously a greedy algorithm problem. Each senate R must ban its next closest senate D who is from another party, or else D will ban its next senate from R's party.

The idea is to use two queues to save the index of each senate from R's and D's parties, respectively. During each round, we delete the banned senate's index; and plus the remainning senate's index with n(the length of the input string senate), then move it to the back of its respective queue.

In each round, we keep poping R and D and push the current senator to the back of the corresponding queue.Finally whichever queue is not empty is the answer. Pop here means banning the senator.
*/

class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        queue<int> rq,dq;
        int n = senate.length();
        for(int i=0;i<n;i++)
            (senate[i]=='R') ? rq.push(i) : dq.push(i);
        
        while(!rq.empty() and !dq.empty())
        {
            rq.front()<dq.front() ? rq.push(rq.front()+n) : dq.push(dq.front()+n);
            rq.pop(),dq.pop();
        }
        return (rq.size()>dq.size()) ? "Radiant" : "Dire";
    }
};
