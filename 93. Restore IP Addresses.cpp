/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]



1. Valid ip address has 4 parts to it. Each part can have max of 3 digits.
2. For a given string, start with 1 char,2 char and 3 char for each part and recursively call upon the remaining string.
3. Whenever the number of digits exceeds the maximum digits possible for the remaining parts at that point of call we have to return
4. Whenever we are at last part, we can simply convert the last 3 or 2 digits to string and add it to answer.
5. Everytime we have to make sure the number is not formed as 0xx. We can have 0. but not 0xx. Whenever we take the first two digits or 3 digits we should only take if it doesnt start with 0. Similarly whenever there is only one part then input has only one character then just add it or while converting we should make sure it doesn't start with 0.

*/
class Solution {
public:
    vector<string> ans;
    void helper(int start,int part, string& inp,string curr)
    {
        int numDigits=inp.size()-start;
        if(numDigits<part or numDigits>3*part)
            return;
        if(part==1) // last part(can contain 1 or 2 or 3 digits max)
        {
            if(numDigits==1 or (inp[start]!='0' and stoi(inp.substr(start))<=255))
                ans.push_back(curr.append(inp.substr(start)));
        }
        else
        {
            helper(start+1,part-1,inp,curr+inp.substr(start,1)+".");
            if(inp[start]!='0')
            {
                helper(start+2,part-1,inp,curr+inp.substr(start,2)+".");
                if(stoi(inp.substr(start,3))<=255)
                    helper(start+3,part-1,inp,curr+inp.substr(start,3)+".");
            }
        }
    }
    vector<string> restoreIpAddresses(string s) 
    {
        helper(0,4,s,"");
        return ans;
    }
};
