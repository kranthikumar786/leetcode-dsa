class Solution {
    public String removeDuplicates(String s) {
     StringBuilder str = new StringBuilder();
     for(char ch : s.toCharArray()){
        int len = str.length();
        if(len > 0 && str.charAt(len-1) == ch) {
              str.deleteCharAt(len-1);
        }else{
            str.append(ch);
        }
     } 
   return str.toString();
    }
}
/**
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
 */