class MinStack {
    Stack<Long> st;
    long minV;

    public MinStack() {
        st = new Stack<>();
    }

    public void push(int val) {
        long v = val;
        if (st.isEmpty()) {
            st.push(v);
            minV = v;
        } else {
            if (v >= minV) {
                st.push(v);
            } else {
                st.push(2 * v - minV);
                minV = v;
            }
        }
    }

    public void pop() {
        long v = st.pop();
        if (v < minV) {
            minV = 2 * minV - v;
        }
    }

    public int top() {
        long v = st.peek();
        if (v < minV) return (int) minV;
        return (int) v;
    }

    public int getMin() {
        return (int) minV;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 
 class MinStack {
    Stack<int[]>st ;
    public MinStack() {
        st = new Stack<>();
    }
    public void push(int val) {
      if(st.isEmpty()){
           st.push(new int[]{val,val});
      }else{
          int prevMin = st.peek()[1];
            int newMin = Math.min(prevMin, val);
            st.push(new int[]{val, newMin});
      }   
    }
    public void pop() {
        st.pop();  
    }
    public int top() {
      return st.peek()[0];    
    }
    public int getMin() {
     return st.peek()[1];   
    }
}
 */