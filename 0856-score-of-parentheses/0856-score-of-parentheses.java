class Solution {
    public int scoreOfParentheses(String s) {
        //int Score = 0;
        //int depth = 0; 
        int n = s.length();
        ArrayDeque<Integer>st = new ArrayDeque<>();
        st.push(0);
        for(int i = 0 ; i < n ; i++){
           if(s.charAt(i) == '('){
                st.push(0);
           } else{
               int inner = st.pop();
               int v = inner == 0 ? 1 : inner*2; 
               st.push(st.pop()+v);
           }
        }
        return st.pop();
    }
}

/**
  if(s.charAt(i) == '('){
                     st.push(i);
              }else{
                  if(st.peek() == ')' && i-st.peek() == 1){
                         pair++;
                  } else{
                      pair = pair*2 ;
                  }
              }
 */