/*
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id


1. We have to store the index and timestamp/snap_id in a map
2. When we take a snap, we just increment the snap_index
3. When we try to get the value for a given index and snap_id then first look for snap_id which is immediately greater than the given snap_id
  a. we use upper_bound to get the next immediate greater element that we are looking for.
  b. If there is a snap_id of 1 and we look for 0 then we get iterator for 1, which is nothing but the start of the nested map.
  c. If there are two elements 1 and 3 and snap_id is 2, then the iterator will be 3 so we go back and take the value of 1. This is because after 1 we took another snap when it is at same state of 1 so no change hence we do not store anything
     we only have to store the latest snap_id when something is set. Query for any snap_id we have to just get the bigger element and go back once.
*/


class SnapshotArray {
public:
    map<int,map<int,int>> nums;
    int snap_index = 0;
    SnapshotArray(int length) 
    {
    }
    void set(int index, int val) 
    {
        nums[index][snap_index]=val;
    }
    int snap() 
    {
        return snap_index++;
    }
    int get(int index, int snap_id) 
    {
        auto it = nums[index].upper_bound(snap_id);
        return it == begin(nums[index]) ? 0 : prev(it)->second;
    }
};
