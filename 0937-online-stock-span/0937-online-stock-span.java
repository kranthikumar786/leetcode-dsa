class StockSpanner {
   Stack<int[]>st ;
    public StockSpanner() {
        st = new Stack<>();
    }
    public int next(int price) {
        int cnt = 1;
        while(!st.isEmpty() &&  st.peek()[0] <= price){
                 cnt += st.pop()[1];
        } 
        st.push(new int[]{price,cnt});
       return cnt;   
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 class StockSpanner {
    List<Integer>l;
    public StockSpanner() {
        l = new ArrayList<>();
    }
    public int next(int price) {
      int cnt = 1;
      if(l.isEmpty()) {
        l.add(price);
        return 1;}
      for(int i = l.size()-1; i >=0 ; i--) {
            if(l.get(i) <= price){
                cnt++;
            }else{
                break;
            } 
      }
      l.add(price);   
     return cnt; 
    }
}
 
 */