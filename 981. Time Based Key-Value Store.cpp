/*
Create a timebased key-value store class TimeMap, that supports two operations.

1. set(string key, string value, int timestamp)

Stores the key and value, along with the given timestamp.
2. get(string key, int timestamp)

Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
If there are multiple such values, it returns the one with the largest timestamp_prev.
If there are no values, it returns the empty string ("").


1. We have to store the index and timestamp/snap_id in a map
2. When we take a snap, we just increment the snap_index
3. When we try to get the value for a given index and snap_id then first look for snap_id which is immediately greater than the given snap_id
  a. we use upper_bound to get the next immediate greater element that we are looking for.
  b. If there is a snap_id of 1 and we look for 0 then we get iterator for 1, which is nothing but the start of the nested map.
  c. If there are two elements 1 and 3 and snap_id is 2, then the iterator will be 3 so we go back and take the value of 1. This is because after 1 we took another snap when it is at same state of 1 so no change hence we do not store anything
     we only have to store the latest snap_id when something is set. Query for any snap_id we have to just get the bigger element and go back once.

*/


class TimeMap {
public:
    map<string,map<int,string>> time;
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        time[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) 
    {
        auto it = time[key].upper_bound(timestamp);
        return it==begin(time[key]) ? "" : prev(it)->second;
    }
};
