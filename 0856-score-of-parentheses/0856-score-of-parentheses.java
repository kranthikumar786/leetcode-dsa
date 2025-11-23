class Solution {
    public int scoreOfParentheses(String s) {
        int Score = 0;
        int depth = 0; 
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
              if(s.charAt(i) == '('){
                depth++;
              } else{
                 depth--;
                 if(s.charAt(i-1) == '('){
                    Score += 1<<depth;
                 }
              }
        }
        return Score;
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