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

/**
class MinStack {
    Stack<Integer>st,minStack;
    public MinStack() {
      st = new Stack<>();
      minStack = new Stack<>();  
    }
    public void push(int val) {
       st.push(val);
       if(minStack.isEmpty()){
       minStack.push(val);
       } else{
       if(minStack.peek() >= st.peek()){
           minStack.push(val);
         } 
       }  
    }
    public void pop() {
     int v = st.pop();
     if(v == minStack.peek()){
         minStack.pop();
     }   
    }
    public int top() {
      return st.isEmpty() ? 0 : st.peek();  
    }
    public int getMin() {
     return minStack.isEmpty() ? 0 : minStack.peek();   
    }
}

 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */