/**

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.


Method-1:

1. Prepare the output based the frequencies. i.e. Highest frequency character comes first and then next highest and so on...
2. First take the counts of each character in the tasks array.
3. Push the counts and character into a priority queue to build a max heap.
4. Until we complete a window(n+1), keep poping and adding it to the output string. If the heap is empty then add a filler character.
5. Finally copy back the remaining characters to priority queue.
**/

Method-1:
---------
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char,int> count;
        for(auto c : tasks)
            count[c]++;
        priority_queue<pair<int,char>> maxHeap;
        for(auto freq : count)
            maxHeap.push({freq.second,freq.first});
        
        string ans="";
        while(!maxHeap.empty())
        {
            queue<pair<int,char>> tempHeap;
            int interval = n+1;
            while(interval-->0)
            {
                if(maxHeap.empty())
                {
                    if(!tempHeap.empty()) // Required when it is last character nothing is left to do for next iteration so don't do anything.
                        ans+="*";
                }
                else
                {
                    auto p = maxHeap.top();
                    maxHeap.pop();
                    ans+=p.second; //append the char
                    p.first--;
                    if(p.first>0)
                        tempHeap.push(p);
                }
            }
            while(!tempHeap.empty())
            {
                maxHeap.push(tempHeap.front());
                tempHeap.pop();
            }
        }
        return ans.size();
       
    }
};


Method - 2:
-----------

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> count(120,0);
        int max_count_char=0;
        int same_max_count_char= 1;
        for(auto c : tasks)
        {
            count[c]++;
            if(count[c]>max_count_char)
            {
                max_count_char=count[c];
                same_max_count_char=1;
            }
            else if(count[c]==max_count_char)
                same_max_count_char++;
        }
        int ans = same_max_count_char+(max_count_char-1)*(n+1);
        ans = max(ans,(int)tasks.size()); // This is because to handle the scenario where unique characters are more than duplicates, in that case ans will be lesser than tasks.size() or when n==0 then also ans will be lesser than tasks.size()
        return ans;
            
    }
};
