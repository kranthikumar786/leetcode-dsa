class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        this -> k = k;
        for (int num : nums) {
            save(num);
        }
    }
    
    int add(int val) {
        if (pq.size() < k || pq.top() < val) {
            save(val);
        }
        return pq.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    void save(int v) {
        pq.push(v);
        if (pq.size() > k) {
            pq.pop();
        }
    }
};