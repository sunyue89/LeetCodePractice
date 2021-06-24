/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 // capacity );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

// hash_map key -> value

class LRUCache {
        
public:
    
    unordered_map <int,int> kv;//key to value
    unordered_map <int,list<int>::iterator> kp;//key to priority indicated as iterator idx of arraylist
    list<int> keys; //bookeeping of the keys
    int cap;

    LRUCache(int capacity) : cap(capacity){}
    
    int get(int key) {
        if(kp.find(key)!=kp.end()){
            //cout<<*kp[key]<<endl;
            keys.erase(kp[key]);
            keys.insert(keys.begin(),key);
            kp[key]=keys.begin();
            return kv[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(kp.find(key)!=kp.end()){
            //cout<<*kp[key]<<endl;
            keys.erase(kp[key]);
        }else{
            if(keys.size()==cap){
                kp.erase(keys.back());
                kv.erase(keys.back());
                keys.pop_back();
            }
        }
        keys.insert(keys.begin(),key);
        kp[key]=keys.begin();
        kv[key] = value;
        //cout<<*kp[key]<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
