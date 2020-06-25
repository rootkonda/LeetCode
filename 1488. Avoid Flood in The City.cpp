Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake which is full of water, there will be a flood. Your goal is to avoid the flood in any lake.

Given an integer array rains where:

rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
Return an array ans where:

ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.

Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes. (see example 4)


https://leetcode.com/problems/avoid-flood-in-the-city/discuss/697687/A-Set-and-A-Map-Lucid-code-with-documented-comments.


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans; // Store the final answer here.
        int n = rains.size(); 
        unordered_map<int, int> fulllakes; // Lake number -> day on which it became full.
        set<int> drydays;     // Set of available days that can be used for drying a full lake.
        for (int i=0; i<n; i++) {  // For each day - 
            if (rains[i] == 0) {  // No rain on this day.
                drydays.insert(i); // This day can be used as a day to dry some lake.
                                   // We don't know which lake to prioritize for drying yet.
                ans.push_back(1);  // Any number would be ok. This will get overwritten eventually.
                                   // If it doesn't get overwritten, its totally ok to dry a lake
                                   // irrespective of whether it is full or empty.
            } else { // Rained in rains[i]-th lake.
                int lake = rains[i]; 
                if (fulllakes.find(lake) != fulllakes.end()) { // If it is already full -
                    // We must dry this lake before it rains in this lake.
                    // So find a day in "drydays" to dry this lake. Obviously, that day must be
                    // a day that is after the day on which the lake was full.
                    // i.e. if the lake got full on 7th day, we must find a dry day that is 
                    // greater than 7.
                    auto it = drydays.lower_bound(fulllakes[lake]);
                    if (it == drydays.end()) { // If there is no available dry day to dry the lake,
                                               // flooding is inevitable.
                        return {}; // Sorry, couldn't stop flooding.
                    }
                    int dryday = *it; // Great, we found a day which we can use to dry this lake.
                    ans[dryday] = lake; // Overwrite the "1" and dry "lake"-th lake instead.
                    drydays.erase(dryday); // We dried "lake"-th lake on "dryday", and we can't use
                                           // the same day to dry any other lake, so remove the day
                                           // from the set of available drydays.
                }
                fulllakes[lake] = i; // Update that the "lake" became full on "i"-th day.
                ans.push_back(-1); // As the problem statement expects.
            }
        }
        return ans; // Congratualtions, you avoided flooding.
    }
};
/*
[1,2,3,4]
[1,2,0,0,2,1]
[1,2,0,1,2]
[69,0,0,0,69]
[10,20,20]
[2,3,0,0,3,1,0,1,0,2,2]
*/
