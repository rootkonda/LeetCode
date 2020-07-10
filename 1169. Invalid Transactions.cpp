/*
A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
Each transaction string transactions[i] consists of comma separated values representing the name, time (in minutes), amount, and city of the transaction.

Given a list of transactions, return a list of transactions that are possibly invalid.  You may return the answer in any order.


*/

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions)
    {
        vector<string> ans;
        unordered_map<string,vector<vector<string>>> vis; // To store list of txn's for a given name just to consolidate all given strings for a particular name.
        unordered_map<string,vector<pair<string,int>>> sec; // To store the name to {city,amount} mapping
        for(auto txn : transactions) // This is to fill up the vis and sec unordered_maps
        {
            vector<string> str;
            int start=0;
            for(int i=0;i<txn.size();i++)
            {
                if(txn[i]==',')
                {
                    str.push_back(txn.substr(start,i-start));
                    start=i+1;
                }
            }
            str.push_back(txn.substr(start));
            vis[str[0]].push_back(str);
            sec[str[0]].push_back({str[3],stoi(str[1])});
        }
        for(auto itr : vis) // Go thru the list of names
        {
            vector<vector<string>> temp = itr.second;
            
            for(int i=0;i<temp.size();i++) // For each person go thru the existing list of cities and amounts and check if they satisfy the condition and then add to answer
            {
                vector<string> item = temp[i];
                if(stoi(item[2])>1000) // As per given condition
                    ans.push_back(item[0]+','+item[1]+','+item[2]+','+item[3]);
                else if(sec[item[0]].size()>1) // If we have more than 1 txn then go inside and check for next given condition.
                {
                    for(int j=0;j<sec[item[0]].size();j++)
                    {
                        if(sec[item[0]][j].first!=item[3] and (abs(stoi(item[1])-sec[item[0]][j].second)<=60))                                               
                        {
                            ans.push_back(item[0]+','+item[1]+','+item[2]+','+item[3]);
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


/*
["alice,20,800,mtv","alice,50,100,beijing","alice,50,100,chennai"]
["alice,20,800,mtv","alice,50,1200,mtv"]
["alice,20,800,mtv","bob,50,1200,mtv"]
["alice,20,800,mtv","alice,50,100,beijing"]
["alex,676,260,bangkok","bob,656,1366,bangkok","alex,393,616,bangkok","bob,820,990,amsterdam","alex,596,1390,amsterdam"]
*/
