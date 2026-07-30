class LRUCache {
private:
    int cap;
    // Stores key-value pairs to handle eviction cleanly
    std::list<std::pair<int, int>> cache; 
    // Maps key -> iterator pointing to the corresponding node in the list
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        
        // Move the accessed node to the front (Most Recently Used)
        cache.splice(cache.begin(), cache, it->second);
        
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        
        if (it != map.end()) {
            // Key exists: update value and move node to the front
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        
        // If capacity reached, remove the Least Recently Used (back of list)
        if (cache.size() == cap) {
            int lastKey = cache.back().first;
            map.erase(lastKey);
            cache.pop_back();
        }
        
        // Insert new key-value pair at the front
        cache.push_front({key, value});
        map[key] = cache.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */