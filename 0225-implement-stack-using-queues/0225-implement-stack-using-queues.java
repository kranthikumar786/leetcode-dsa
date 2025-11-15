class MyStack {
  Deque<Integer>q2;
    public MyStack() {
      q2 = new LinkedList<>();  
    }
    public void push(int x) { 
      q2.addLast(x);
    }
    public int pop() {    
     int la = q2.removeLast();
    return la;
    }
    public int top() {
      return q2.peekLast();   
    }
    public boolean empty() {
     return q2.isEmpty();   
    }
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */