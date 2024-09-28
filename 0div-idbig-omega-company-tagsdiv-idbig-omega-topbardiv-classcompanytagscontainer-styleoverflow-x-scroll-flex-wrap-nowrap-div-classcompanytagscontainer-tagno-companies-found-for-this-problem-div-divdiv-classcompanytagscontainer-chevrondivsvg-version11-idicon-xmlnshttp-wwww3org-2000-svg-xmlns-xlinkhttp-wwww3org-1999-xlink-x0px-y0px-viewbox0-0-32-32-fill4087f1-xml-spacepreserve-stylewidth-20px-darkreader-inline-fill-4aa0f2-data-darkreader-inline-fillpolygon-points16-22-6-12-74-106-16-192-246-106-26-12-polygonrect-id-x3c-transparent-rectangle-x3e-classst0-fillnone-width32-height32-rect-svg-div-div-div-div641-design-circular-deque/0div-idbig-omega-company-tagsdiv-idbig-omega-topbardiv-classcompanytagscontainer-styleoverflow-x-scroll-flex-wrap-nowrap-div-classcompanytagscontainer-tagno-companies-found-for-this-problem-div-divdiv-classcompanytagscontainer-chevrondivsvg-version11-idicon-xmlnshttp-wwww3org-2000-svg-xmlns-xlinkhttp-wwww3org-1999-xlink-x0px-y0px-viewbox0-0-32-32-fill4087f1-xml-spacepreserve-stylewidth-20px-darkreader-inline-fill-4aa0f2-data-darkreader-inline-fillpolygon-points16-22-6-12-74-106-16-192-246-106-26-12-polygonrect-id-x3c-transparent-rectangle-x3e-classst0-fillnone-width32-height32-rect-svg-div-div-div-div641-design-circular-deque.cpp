class MyCircularDeque {
    vector<int> v;
    int front = 1, back = 0, sz = 0, max_sz = 0;
    int id(int i) { return (max_sz + i % max_sz) % max_sz; }
public:    
    MyCircularDeque(int k) : max_sz(k) { v.resize(max_sz); }
    bool insertFront(int value) {
        if (isFull())
            return false;
        ++sz;
        v[id(--front)] = value;
        return true;
    }
    bool insertLast(int value) {
        if (isFull())
            return false;
        ++sz;
        v[id(++back)] = value;
        return true;
    }
    bool deleteFront() {
        if (isEmpty())
            return false;
        --sz;
        ++front;
        return true;        
    }
    bool deleteLast() {
        if (isEmpty())
            return false;
        --sz;
        --back;
        return true;
    }
    int getFront() { return isEmpty() ? -1 : v[id(front)]; }
    int getRear() { return isEmpty() ? -1 : v[id(back)]; }
    bool isEmpty() { return sz == 0; }
    bool isFull() { return sz == max_sz; }
};
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */