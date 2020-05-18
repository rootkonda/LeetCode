/*
Given a list of folders, remove all sub-folders in those folders and return in any order the folders after removing.

If a folder[i] is located within another folder[j], it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.

Idea is to find the smallest common prefix in the given list of strings and add that to the answer.
*/


class Solution {
public:
    
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<string,bool> present; // bool is keep track of whether it is available to add it to the answer
        vector<string> ans;
        for(auto str : folder)
            present.insert({str,true});
        for(int i=0;i<folder.size();i++)
        {
            string temp="";
            int k=0;
            while(k<folder[i].size())
            {
                temp+="/";
                k++;
                while(k<folder[i].size() and folder[i][k]!='/') // To take the substring as there can be more chars after each / character.
                {
                    temp+=folder[i][k];
                    k++;
                }
                if(present.count(temp)>0)
                {
                    if(present[temp])
                        ans.push_back(temp);
                    present[temp]=false;
                    break; // Because we found the string prefix so break to save time.
                }
            } 
        }
        return ans;
    }
};
