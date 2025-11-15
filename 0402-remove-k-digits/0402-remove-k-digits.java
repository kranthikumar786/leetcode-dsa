class Solution {
    public String removeKdigits(String num, int k) {
      Stack<Character>st = new Stack<>();
      for(char c : num.toCharArray()){
             while(!st.isEmpty() && st.peek() >c && k > 0){
                   st.pop();
                   k--;
             }
           st.push(c);  
      }
       while(k > 0) {
          st.pop();
          k--;
       }  
        StringBuilder str = new StringBuilder();
        for(char c : st){
            str.append(c);
        }
        while(str.length() > 0 && str.charAt(0) == '0'){
                str.deleteCharAt(0);
        }  
       return str.length() == 0 ? "0" : str.toString(); 
    }
}