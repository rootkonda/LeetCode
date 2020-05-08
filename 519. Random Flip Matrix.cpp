/*
You are given the number of rows n_rows and number of columns n_cols of a 2D binary matrix where all values are initially 0. Write a function flip which chooses a 0 value uniformly at random, changes it to 1, and then returns the position [row.id, col.id] of that value. Also, write a function reset which sets all values back to 0. Try to minimize the number of calls to system's Math.random() and optimize the time and space complexity.

*/



class Solution {
public:
    int row=0,col=0;
    unordered_set<int> dup;
    int total;
    Solution(int n_rows, int n_cols) {
        total = n_rows*n_cols;
        row = n_rows;
        col = n_cols;
    }
    
    vector<int> flip() 
    {
        if(dup.size()==total)
            return {};
        int rdm = rand()%total;
        while(dup.find(rdm)!=dup.end())
            rdm = (++rdm%total);
        dup.insert(rdm);
        return {rdm/col,rdm%col};
    }
    
    void reset() {
        dup = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

