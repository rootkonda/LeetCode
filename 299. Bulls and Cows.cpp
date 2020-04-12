/**

You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Approach: Two parts. First part, find the bulls and replace the digit with 'A' or any character. Second look for cows and when you find one, replace it with 'A'; Finally prepare the answer and return.

**/

class Solution {
public:
    string getHint(string secret, string guess) 
    {

        int bulls=0,cows=0;
        int idx=0;
        
        for(int i=0;i<guess.size();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
                secret[i]='A';
                guess[i]='A';
               
            }
        }
        for(int i=0;i<guess.size();i++)
        {
            if(guess[i]!='A' and secret.find(guess[i])!=string::npos)
            {
                idx=secret.find(guess[i]);
                secret[idx]='A';
                guess[i]='A';
                cows++;
            }
        }
        string ans="";
        ans+=to_string(bulls);
        ans+="A";
        ans+=to_string(cows);
        ans+="B";
        return ans;
        
    }
};
