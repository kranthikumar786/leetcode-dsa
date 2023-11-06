class MyHashSet {
public:
    vector<bool>HashSet;
    MyHashSet() {
        HashSet.resize(1000001, 0);
    }
    
    void add(int key) {
       HashSet[key] = 1; 
        
    }
    
    void remove(int key) {
        
        if(contains(key)){
         HashSet[key] = 0;
        }   
    }
    bool contains(int key) {
        return HashSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 
 https://leetcode.com/problems/design-hashset/solutions/3576956/daily-leetcoding-challenge-may-day-30/
 
 */