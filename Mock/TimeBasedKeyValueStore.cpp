/*Create a timebased key-value store class TimeMap, that supports two operations.

1. set(string key, string value, int timestamp)

Stores the key and value, along with the given timestamp.
2. get(string key, int timestamp)

Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
If there are multiple such values, it returns the one with the largest timestamp_prev.
If there are no values, it returns the empty string ("").
 

Example 1:

Input: inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
Output: [null,null,"bar","bar",null,"bar2","bar2"]
Explanation:   
TimeMap kv;   
kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1   
kv.get("foo", 1);  // output "bar"   
kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"   
kv.set("foo", "bar2", 4);   
kv.get("foo", 4); // output "bar2"   
kv.get("foo", 5); //output "bar2"   

Example 2:

Input: inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
Output: [null,null,null,"","high","high","low","low"]
 

Note:

All key/value strings are lowercase.
All key/value strings have length in the range [1, 100]
The timestamps for all TimeMap.set operations are strictly increasing.
1 <= timestamp <= 10^7
TimeMap.set and TimeMap.get functions will be called a total of 120000 times (combined) per test case.
Last Submission
Last Saved Code*/


class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        idx=0;
    }
    
    void set(string key, string value, int timestamp) {
        if(keyIdx.find(key)==keyIdx.end()){
            keyIdx[key] = idx;
            timeStamp.push_back({timestamp});
            Val.push_back({value});
            idx++;
        }else{
            timeStamp[keyIdx[key]].push_back(timestamp);
            Val[keyIdx[key]].push_back(value);
        }
    }
    
    string get(string key, int timestamp) {
        if(keyIdx.find(key)==keyIdx.end()){
            return "";
        }else{
            int id = BS(keyIdx[key],timestamp);
            if(id==-1)
                return "";
            else
                return Val[keyIdx[key]][id];
        }
    }
private:
    int idx;
    unordered_map <string,int> keyIdx; //map string to idx
    vector<vector<int>> timeStamp; //map idx and timestamp
    vector<vector<string>> Val;
    
    int BS(int kI, int t){
        int lo = 0;
        int hi = timeStamp[kI].size()-1;
        int fl = -1;
        while (lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(timeStamp[kI][mid]==t)
                return mid;
            if(timeStamp[kI][mid]<t){
                lo = mid+1;
                fl = mid;
            }else{
                hi = mid-1;
            }
        }
        return fl;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
