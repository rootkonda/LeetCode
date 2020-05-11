/*
Given a string, sort it in decreasing order based on the frequency of characters.

https://www.ascii-code.com/

1. The first 32 characters in the ASCII-table are unprintable control codes and are used to control peripherals such as printers.
2. Codes 32-127 are common for all the different variations of the ASCII table, they are called printable characters, represent letters, digits, punctuation marks, and a few miscellaneous symbols. You will find almost every character on your keyboard. Character 127 represents the command DEL.
3. characters 128-255 are extended ASCII codes.

O(128log(128))+O(s)+O(128);
*/


class Solution {
public:
    string frequencySort(string s) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(s=="")
            return "";
        string ans="";
        vector<pair<int,string>> ascii(128);// To consider all kinds of printable characters ASCII table.
        int index = 0;
        for(int i=0;i<s.size();i++)
        {
            int v = (int)s[i]; //Every time we see same character, go to the same index and update its count. Converting character to its ASCII value(int)
            ascii[v].first++; //Count of this character
            ascii[v].second.push_back(s[i]); // Prepare the string everytime we find it.
        }
        sort(ascii.begin(),ascii.end(),greater<>()); // Sort in descending order
        for(int i=0;i<128;i++)
        {
            if(ascii[i].first==0) // No characters left so break;
                break;
            ans+=(ascii[i].second); //Append it to the answer.
        }
        
        return ans;
    }
};
