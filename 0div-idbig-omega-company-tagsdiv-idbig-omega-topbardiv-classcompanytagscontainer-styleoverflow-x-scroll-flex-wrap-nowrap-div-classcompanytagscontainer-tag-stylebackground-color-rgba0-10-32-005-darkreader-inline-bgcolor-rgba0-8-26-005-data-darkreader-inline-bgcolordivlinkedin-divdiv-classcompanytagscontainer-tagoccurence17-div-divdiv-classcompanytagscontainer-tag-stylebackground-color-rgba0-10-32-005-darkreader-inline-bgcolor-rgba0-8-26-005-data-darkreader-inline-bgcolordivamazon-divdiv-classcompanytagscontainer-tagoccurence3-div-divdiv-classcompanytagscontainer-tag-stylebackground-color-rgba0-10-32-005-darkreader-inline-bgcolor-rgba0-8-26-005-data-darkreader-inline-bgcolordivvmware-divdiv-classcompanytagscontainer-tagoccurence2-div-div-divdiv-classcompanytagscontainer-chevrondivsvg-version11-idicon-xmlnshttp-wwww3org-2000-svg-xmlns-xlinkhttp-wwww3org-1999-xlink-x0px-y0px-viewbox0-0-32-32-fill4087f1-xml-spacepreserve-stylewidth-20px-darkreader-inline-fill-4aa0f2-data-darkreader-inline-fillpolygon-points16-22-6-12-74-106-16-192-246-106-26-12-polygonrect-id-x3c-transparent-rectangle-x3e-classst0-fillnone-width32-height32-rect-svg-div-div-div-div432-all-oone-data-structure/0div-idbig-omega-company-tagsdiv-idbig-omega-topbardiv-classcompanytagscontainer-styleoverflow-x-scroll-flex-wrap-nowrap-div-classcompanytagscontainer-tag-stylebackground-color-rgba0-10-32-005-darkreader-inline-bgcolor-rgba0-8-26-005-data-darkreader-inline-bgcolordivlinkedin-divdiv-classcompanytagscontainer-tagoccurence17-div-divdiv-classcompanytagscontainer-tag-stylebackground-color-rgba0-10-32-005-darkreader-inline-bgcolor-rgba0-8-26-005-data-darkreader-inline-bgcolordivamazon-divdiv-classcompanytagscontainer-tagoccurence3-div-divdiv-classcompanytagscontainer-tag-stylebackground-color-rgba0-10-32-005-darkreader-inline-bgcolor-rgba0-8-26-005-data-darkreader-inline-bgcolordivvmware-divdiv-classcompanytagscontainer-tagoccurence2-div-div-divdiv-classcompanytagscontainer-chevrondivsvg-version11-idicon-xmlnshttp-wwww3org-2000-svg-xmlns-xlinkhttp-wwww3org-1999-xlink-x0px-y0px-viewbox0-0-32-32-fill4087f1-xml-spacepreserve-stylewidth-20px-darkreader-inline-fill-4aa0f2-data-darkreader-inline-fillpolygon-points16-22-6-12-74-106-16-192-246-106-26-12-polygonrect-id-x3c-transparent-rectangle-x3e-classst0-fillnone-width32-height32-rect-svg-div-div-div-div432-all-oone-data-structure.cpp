class AllOne {
public:
    unordered_map<int, unordered_set<string>> t;
    unordered_map<string, int> m;
    int largest = 0, smallest = INT_MAX;
    
    void inc(string key) {
        int freq = m[key];
        if (freq > 0) {
            t[freq].erase(key);
            if (t[freq].empty()) {
                t.erase(freq);
                if (smallest == freq) ++smallest;
            }
        }
        
        m[key] = ++freq;
        t[freq].insert(key);
        largest = max(largest, freq);
        smallest = min(smallest, freq);
    }
    
    void dec(string key) {
        int freq = m[key];
        if (!freq) return;
        
        t[freq].erase(key);
        if (t[freq].empty()) {
            t.erase(freq);
            if (smallest == freq) {
                if (t.empty()) {
                    smallest = INT_MAX;
                } else {
                    smallest = freq + 1;
                    while (smallest <= largest && t.find(smallest) == t.end()) 
                        ++smallest;
                }
            }
        }
        
        if (--freq == 0) {
            m.erase(key);
        } else {
            m[key] = freq;
            t[freq].insert(key);
            smallest = min(smallest, freq);
        }
        
        if (t.find(largest) == t.end()) --largest;
        
    }
    
    string getMaxKey() {
        if (t.empty()) return "";
        return *t[largest].begin();
    }
    
    string getMinKey() {
        if (t.empty()) return "";
        return *t[smallest].begin();
    }
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */