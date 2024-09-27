class MyCalendarTwo {
public:
    map<int, int>hm;
    bool book(int start, int end) {
        hm[start]++;
        hm[end]--;
        
        int books = 0;
        for (auto it = hm.begin(); it != hm.end(); it++) {
            books += it->second;
            if (books >= 3) {
                hm[start]--;
                hm[end]++;
                return false;
            }
        }
        return true;
    }
};
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */