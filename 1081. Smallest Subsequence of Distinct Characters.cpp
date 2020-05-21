/*

Problem is to remove duplicates and output a string with unique characters while maintaing the smallest(lexicographically) permutation of all possible subsequences of distinct characters.

1. We have to just keep adding the unique characters to the answer and while adding them we have to check if the character to be added is smaller than the character which we have added previuosly to the answer.
2. If it is smaller, then we can check whether the previous character is available for use in future iterations ? If yes, then we can just remove the character we added previously. Repeat this step, until we find a previous character smaller than current character.
3. We can now add the current character to the answer.

*/
 class Solution {
  public:
      string smallestSubsequence(string text)
      {
          int last[26] = {};
          int seen[26] = {};
          int n = (int)text.size();
          string ans="";
          for(int i=0;i<n;i++)
              last[text[i]-'a'] = i; // In order to know the last occurence of a character(step 2 above).At any point if we want to know that a given character is available in the future iterations.
          
          for(int i=0;i<n;i++)
          {
              if(seen[text[i]-'a'])
                  continue;
              seen[text[i]-'a']++; // To avoid adding duplicates
              while(!ans.empty() and ans.back()>text[i] and i<last[ans.back()-'a']) // As explained in step 2 above.
              {
                  seen[ans.back()-'a'] = 0; // We have to reset this character in seen to 0 because when it comes again in future, it has to be added to the answer again.
                  ans.pop_back();
              }
              
              ans.push_back(text[i]);
          }
          return ans;
      }
};
