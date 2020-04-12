/**
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Simple and straightforward. Just follow the rules in questions.
**/

class Solution
{
public:
    bool checkRecord(string s)
    {
        int countA = 0;
        int countL = 0;
        int count = 1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A')
                countA++;
            else if(s[i]=='L')
            {
                while(i+1<s.size())
                {
                    if(s[i]=='L' and s[i+1]=='L')
                        count++;
                    else
                        break;
                    i++;
                }
                countL = max(countL,count);
                count=1;
            }
        }
        if(countA>1 or countL>2)
            return false;
        return true;
    }
};
