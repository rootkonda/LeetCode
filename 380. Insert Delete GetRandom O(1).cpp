/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

Explanation
-----------
1. Average O(1) means either unordered_set or unordered_map. But in order to retreive in O(1) time then make sure to store the location of inserted value in a vector inside a map. So meaning, we vector to store the new values and also unordered_map to store the index in vector against a given value.

2. In order to remove the value from the vector in O(1) time we can do this trick.
  a. First find the index in the vector of the value to be removed.
  b. Next, replace the value at that index in vector with the value of the last element in the vector.
  c. Pop the last element from vector
  d. Update the map for the last value to have the new index position.
  e. Erase the old value from map
  
3. rand() gives a random value from 0 ~ 32768 so we have to take the remainder to get the index.

*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> pos;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if(pos.count(val)>0)
            return false;
        nums.emplace_back(val);
        pos[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if(pos.count(val)==0)
            return false;
        int last = nums.back();
        nums[pos[val]] = last;
        pos[last] = pos[val]; 
        nums.pop_back();
        pos.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        return nums[rand()%nums.size()];    
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
