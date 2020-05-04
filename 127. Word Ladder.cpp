/**
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.


This is a Graph problem to find the shortest path from begin to end string.
1. Take the beginWord and push it to queue.
2. Form the adjacency list, by replacing each character in the string with a-z characters and check if it exists in the map.
3. If it exists then there is a word with 1 character difference and add it to the queue for the next iteration. So for this level add all the valid adjacent nodes into the queue.
4. Process all nodes at the current level and keep adding the children to the queue.
5. Everytime check if the current string is equal to the endWord, i.e. if we have reached the endWord so return current level +1. i.e. intially level = 0 so if the first node matches the end word we return level+1.

**/



 class Solution {
 public:
     int ladderLength(string beginWord, string endWord, vector<string>& wordList)
     {
         unordered_set<string> not_visited{wordList.begin(),wordList.end()};
         queue<string> nodes;
         nodes.emplace(beginWord);
         not_visited.erase(beginWord);
         int level = 0;
         int nodes_level = nodes.size();
         
         while(!nodes.empty())
         {
             string curr = nodes.front();
             nodes.pop();
             if(curr == endWord)
                 return level+1;
             for(int i=0;i<curr.size();i++)
             {
                 char c = curr[i];
                 
                 for(int k=0;k<26;k++)
                 {
                     curr[i] = 'a'+k;
                     if(not_visited.find(curr)!=not_visited.end())
                     {
                         nodes.emplace(curr);
                         not_visited.erase(curr);
                     }
                 }
                 curr[i] = c;
             }
             nodes_level--;
             if(nodes_level==0)
             {
                 nodes_level=nodes.size();
                 level++; // All nodes at the current level is processed and still not reached the endWord so we are going to second level hence level++;
             }
         }
         return 0;
     }
 };
  
