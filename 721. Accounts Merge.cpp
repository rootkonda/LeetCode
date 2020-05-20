/*
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].
*/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        unordered_map<string,vector<string>> graph; // Prepare a graph for each connected email address. Establish the link between the 1st email address to the rest.
        unordered_map<string,string> email_to_name; // For every email, store the name for later use.
        
        for(auto account : accounts)
        {
            for(int i=1;i<account.size();i++)
            {
                email_to_name[account[i]] = account[0];
                graph[account[1]].push_back(account[i]); // If there are multiple emails related then they are added to the vector of emails.
                graph[account[i]].push_back(account[1]);
            }
        }
        
        vector<vector<string>> ans;
        unordered_map<string,bool> visited; // We are going to take each vertex and traverse all its edges and mark each vertex as visited to avoid duplicate work.
        for(auto vertex : graph)
        {
            if(!visited[vertex.first])
            {
                vector<string> connected_emails{email_to_name[vertex.first]}; // Get the name
                stack<string> emails; // To traverse thru the edges
                emails.push(vertex.first);
                visited[vertex.first] = true;
                while(!emails.empty())
                {
                    string curr = emails.top();
                    connected_emails.push_back(curr);
                    emails.pop();
                    
                    for(auto edge : graph[curr])
                    {
                        if(!visited[edge])
                        {
                            emails.push(edge);
                            visited[edge] = true; // We have to mark it as true so that when we go back again we shouldnt pick the same edge again or it goes in infinite loop.
                        }
                    }
                }
                sort(connected_emails.begin()+1,connected_emails.end()); // sort emails only
                ans.push_back(connected_emails); 
            }
        }
        return ans;
    }
};


