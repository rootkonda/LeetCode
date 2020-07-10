/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

*/
class NumArray {
public:
    vector<int> st,arr;
    int n;
    int BuildSegTree(int ss, int se, vector<int>& nums, int si)
    {
        if(ss==se)
            return st[si]=nums[ss];
        int mid = (ss+(se-ss)/2);
        int left = BuildSegTree(ss,mid,nums,(2*si)+1);
        int right = BuildSegTree(mid+1,se,nums,(2*si)+2);
        return st[si]=left+right;
    }
    int RangeSum(int ss, int se, int qs, int qe, int si)
    {
        if(ss>=qs and se<=qe)
            return st[si];
        else if(ss>qe or se<qs)
            return 0;
        else
        {
            int mid = (ss+(se-ss)/2);
            int left = RangeSum(ss,mid,qs,qe,(2*si)+1);
            int right = RangeSum(mid+1,se,qs,qe,(2*si)+2);
            return left+right;
        }
        return 0;
    }
    void Update(int ss, int se, int index, int val, int si)
    {
        if(index>=ss and index<=se)
            st[si]+=val;
        if(ss!=se)
        {
            int mid = (ss+(se-ss)/2);
            Update(ss,mid,index,val,(2*si)+1);
            Update(mid+1,se,index,val,(2*si)+2);
        }
    }
    NumArray(vector<int>& nums) 
    {
        n=nums.size();
        if(n)
        {
            arr=nums;
            int x = (int)(ceil(log2(n)));
            st.resize(2*(int)pow(2,x)-1);
            BuildSegTree(0,n-1,nums,0); 
        }  
    }
    void update(int i, int val) 
    {
        if(i>=n or n==0)
            return;
        Update(0,n-1,i,val-arr[i],0);
        arr[i] = val;
    }
    
    int sumRange(int i, int j) 
    {
        return RangeSum(0,n-1,i,j,0);    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
