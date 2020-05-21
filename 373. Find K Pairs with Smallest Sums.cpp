/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) 
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int, int>>>,greater<pair<int,pair<int,int>>>> pq; // This syntax is for constructing min Heap.
        set<pair<int,int>> dup; // To avoid considering duplicate indices
        if(A.size()==0 or B.size()==0)
            return ans;
        
        pq.push({A[0]+B[0],{0,0}}); // Format of the queue is sum, index0 of A and index0 B and so on for each item
        dup.insert({0,0}); Pushed it into the queue so mark it as visited.
        int K = (B.size()*A.size());
        if(k>K)
            k=K;
            
        while(k-->0)
        {
            pair<int,pair<int,int>> temp1 = pq.top();
            pq.pop();
            int i = temp1.second.first;
            int j = temp1.second.second;
            ans.push_back({A[i],B[j]});
            // Two ways of choosing an element here. Either i+1,j or i,j+1 and we have to try both of them and choose whichever is minimum(priority queue takes care of that) Next time we pop we only get minimum value. Remember these are the only two options here
            if(i+1<A.size() and dup.count({i+1,j})==0)
            {
                pq.push({A[i+1]+B[j],{i+1,j}});
                dup.insert({i+1,j});
            }
            if(j+1<B.size() and dup.count({i,j+1})==0)
            {
                pq.push({A[i]+B[j+1],{i,j+1}});
                dup.insert({i,j+1});
            }
        }
        
        return ans;
    }
};
