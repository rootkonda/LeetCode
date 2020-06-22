/*


An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.

Note:

2 <= S.length <= 100
S will only contain lowercase letters and digits 2 through 9.
S starts with a letter.
1 <= K <= 10^9
The decoded string is guaranteed to have less than 2^63 letters.



1. Find the total length of decoded string.
2. Trace from the back and check for digits. When its a digit, look for the length string that was used to repeat for this digit.
3. When we divide it by that digit, then we get the original length of string used for repeatition.
4. K%=len will reduce the search space if K is bigger than len.
5. Whenever K==0 or K==len then it means we reached the Kth index.

*/

typedef long long ll;
class Solution {
public:
    string decodeAtIndex(string S, int K) 
    {
        ll len=0;
        for(int i=0;i<S.size();i++)
        {
            if(isdigit(S[i]))
                len*=(S[i]-'0');
            else
                len++;
        }
        for(int i=S.size()-1;i>=0;i--)
        {
            if(isdigit(S[i]))
            {
                len/=(S[i]-'0');
                K%=len;
            }
            else
            {
                if(K==len or K==0)
                    return string(1,S[i]);
                len--;
            }
        }
        return "";
    }
};
