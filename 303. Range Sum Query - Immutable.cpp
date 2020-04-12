/**
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

Typical segment tree approach for calculating range sums.
**/

class NumArray {
public:
    int st[100000];
    int n=0;
    inline int GetMid(int a,int b)
    {
        return (a+(b-a)/2);
    }
    int BuildSegTree(vector<int>& arr,int ss,int se, int si)
    {
        int mid,left,right;

        if(ss==se)
        {
            st[si]=arr[ss];
            return st[si];
        }
        else
        {
            mid=GetMid(ss,se);
            left=BuildSegTree(arr,ss,mid,(2*si)+1);
            right=BuildSegTree(arr,mid+1,se,(2*si)+2);

            st[si]=left+right;
            return st[si];
        }
    }
    int RangeSum(int ss, int se, int qs, int qe, int si)
    {
        int mid,left,right;

        if((ss>=qs && se<=qe))
        {
            return st[si];
        }
        else if(ss >qe || se <qs)
        {
            return 0;
        }
        else
        {
            mid=GetMid(ss, se);
            left=RangeSum(ss,mid,qs,qe,(2*si)+1);
            right=RangeSum(mid+1, se, qs, qe,(2*si)+2);
            return left+right;
        }
    }
    NumArray(vector<int>& nums) 
    {
        n = nums.size();
        if(n>0)
            BuildSegTree(nums, 0, n-1, 0);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
    }
    
    int sumRange(int p, int q) 
    {
        return RangeSum(0,n-1,p,q,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
