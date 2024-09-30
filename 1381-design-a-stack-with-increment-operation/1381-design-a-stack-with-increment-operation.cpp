class CustomStack {
public:
     int currentSize,GlobalMax; 
     vector<int>KranthiStack;
    CustomStack(int maxSize) {
     KranthiStack.resize(maxSize);   
        GlobalMax = maxSize;
        currentSize = -1;
    }
    void push(int x) {
       if(currentSize < GlobalMax-1) {
           KranthiStack[++currentSize] = x;
       }
    }
    int pop() {
         if(currentSize >= 0) return KranthiStack[currentSize--];
        return -1;
        }

    void increment(int k, int val) {
       for(int i = 0 ; i < min(k,currentSize+1) ; i++) {
           KranthiStack[i] += val; 
       }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */