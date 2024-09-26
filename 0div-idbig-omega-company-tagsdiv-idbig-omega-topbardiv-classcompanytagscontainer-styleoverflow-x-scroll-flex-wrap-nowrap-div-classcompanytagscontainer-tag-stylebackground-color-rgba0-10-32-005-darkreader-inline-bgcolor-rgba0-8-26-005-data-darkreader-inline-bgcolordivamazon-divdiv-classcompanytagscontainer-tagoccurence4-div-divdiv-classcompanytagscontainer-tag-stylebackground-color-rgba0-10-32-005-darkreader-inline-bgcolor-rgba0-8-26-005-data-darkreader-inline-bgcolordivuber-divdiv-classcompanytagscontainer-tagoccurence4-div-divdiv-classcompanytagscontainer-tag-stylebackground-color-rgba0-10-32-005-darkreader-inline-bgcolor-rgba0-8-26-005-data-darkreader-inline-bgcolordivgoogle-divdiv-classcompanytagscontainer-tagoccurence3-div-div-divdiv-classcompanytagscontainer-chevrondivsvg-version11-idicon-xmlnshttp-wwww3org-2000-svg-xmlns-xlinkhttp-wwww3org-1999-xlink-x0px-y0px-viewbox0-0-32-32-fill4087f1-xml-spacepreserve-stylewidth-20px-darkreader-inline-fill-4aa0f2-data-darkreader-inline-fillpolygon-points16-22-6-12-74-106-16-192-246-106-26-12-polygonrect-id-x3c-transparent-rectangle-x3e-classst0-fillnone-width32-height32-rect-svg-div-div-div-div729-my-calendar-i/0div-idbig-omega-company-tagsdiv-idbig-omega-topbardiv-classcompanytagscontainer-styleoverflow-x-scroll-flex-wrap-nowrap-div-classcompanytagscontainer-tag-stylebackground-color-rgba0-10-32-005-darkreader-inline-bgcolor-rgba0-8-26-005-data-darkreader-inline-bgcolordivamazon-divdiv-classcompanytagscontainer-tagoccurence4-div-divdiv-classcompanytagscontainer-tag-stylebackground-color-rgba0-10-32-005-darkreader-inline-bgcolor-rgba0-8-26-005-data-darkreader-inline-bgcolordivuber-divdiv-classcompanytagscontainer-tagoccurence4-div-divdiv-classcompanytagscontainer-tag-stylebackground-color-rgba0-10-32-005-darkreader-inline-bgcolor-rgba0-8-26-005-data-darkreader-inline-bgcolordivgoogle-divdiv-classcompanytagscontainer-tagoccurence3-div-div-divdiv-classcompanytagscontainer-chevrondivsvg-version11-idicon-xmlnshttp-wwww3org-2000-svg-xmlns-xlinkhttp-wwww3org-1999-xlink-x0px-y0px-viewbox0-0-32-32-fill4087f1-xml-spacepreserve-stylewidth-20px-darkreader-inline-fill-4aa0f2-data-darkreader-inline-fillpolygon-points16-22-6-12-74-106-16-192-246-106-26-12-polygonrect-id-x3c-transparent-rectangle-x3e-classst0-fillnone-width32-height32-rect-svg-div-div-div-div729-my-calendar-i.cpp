class MyCalendar {
public:
 unordered_map<int,int>Booking;
    MyCalendar() {
      Booking.clear();
    }
    bool book(int start, int end) {
       for(auto i = Booking.begin(); i != Booking.end() ; i++) {
                if(start < i->second && i->first < end)
                    return false;
            }
       Booking[start] = end;
       return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */