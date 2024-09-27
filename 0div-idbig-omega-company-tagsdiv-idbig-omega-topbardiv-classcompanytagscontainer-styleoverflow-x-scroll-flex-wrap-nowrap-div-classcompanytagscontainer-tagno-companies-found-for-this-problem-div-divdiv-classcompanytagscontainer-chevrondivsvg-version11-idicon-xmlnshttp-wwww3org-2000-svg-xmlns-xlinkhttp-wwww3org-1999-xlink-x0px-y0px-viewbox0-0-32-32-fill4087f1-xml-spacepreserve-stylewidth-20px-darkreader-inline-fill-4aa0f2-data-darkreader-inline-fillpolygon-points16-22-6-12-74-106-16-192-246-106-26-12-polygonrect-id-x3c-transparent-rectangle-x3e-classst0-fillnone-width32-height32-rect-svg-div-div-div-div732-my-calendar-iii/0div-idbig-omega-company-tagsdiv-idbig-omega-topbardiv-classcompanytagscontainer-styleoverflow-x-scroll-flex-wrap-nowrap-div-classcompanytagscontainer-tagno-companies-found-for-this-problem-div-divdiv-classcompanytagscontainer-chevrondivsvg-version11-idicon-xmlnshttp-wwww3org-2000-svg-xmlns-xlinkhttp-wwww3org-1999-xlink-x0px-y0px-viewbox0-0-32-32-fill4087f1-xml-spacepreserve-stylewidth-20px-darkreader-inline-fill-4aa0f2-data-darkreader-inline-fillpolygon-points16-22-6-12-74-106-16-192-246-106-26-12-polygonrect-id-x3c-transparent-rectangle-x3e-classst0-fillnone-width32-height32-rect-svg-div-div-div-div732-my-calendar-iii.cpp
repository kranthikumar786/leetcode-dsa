class MyCalendarThree {
public:
    map<int,int> event;
    int max_count=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int current_count=0;
        event[start]++;
        event[end]--;
        for (auto val: event){
            current_count+= val.second;
            max_count= max(max_count, current_count);
        }
        return max_count;
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */