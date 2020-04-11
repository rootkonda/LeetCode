/**
  The count-and-say sequence is the sequence of integers with the first five terms as following:

  1.     1
  2.     11
  3.     21
  4.     1211
  5.     111221
  1 is read off as "one 1" or 11.
  11 is read off as "two 1s" or 21.
  21 is read off as "one 2, then one 1" or 1211.

  Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

  Note: Each term of the sequence of integers will be represented as a string.
  
  Approach:
   
  At every iteration, we have to process the previous string and create new string based on that and then assign it back as previous.
  
class Solution 
{
public:
    string countAndSay(int n) 
    {
        if(n==1)
            return "1";
        string prev="1";
        string curr="";
        for(int i=2;i<=n;i++)
        {
            int count=1;
            int plen=prev.length();
            for(int j=0;j<plen;j++)
            {
                if(j+1<plen and prev[j]==prev[j+1])
                    count++;
                else
                {
                    curr+=to_string(count);
                    curr.push_back(prev[j]);
                    count=1;
                }
            }
            prev=curr;
            curr.clear();
        }
        return prev;
    }
};
