class Solution {
    public String removeDuplicates(String s) {
      Stack<Character>st = new Stack<>();
     for(char ch : s.toCharArray()){
        if(!st.isEmpty() && st.peek() == ch){
            st.pop();  
        }else{
             st.add(ch);
        }
     }
     StringBuilder str = new StringBuilder();
       while(!st.isEmpty()){
          str.append(st.pop());
       } 
       return str.reverse().toString();
    }
}