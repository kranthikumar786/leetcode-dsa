class MyStack {
    Queue<Integer>q1,q2;
    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }
    public void push(int x) {
     q2.add(x);   
    }
    public int pop() {
      while(q2.size() > 1) {
          q1.add(q2.remove());
      }   
      int last = q2.remove();
      Queue<Integer>t = q2;
      q2 = q1;
      q1 = t;
     return last;
    }
    public int top() {
        int topV  = -1;
        while(!q2.isEmpty()) {
        topV = q2.remove();
          q1.add(topV);
      }   
      Queue<Integer>t = q2;
      q2 = q1;
      q1 = t;
     return topV;
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