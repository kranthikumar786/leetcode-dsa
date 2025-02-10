class Solution {
    public boolean isDigit(char c ){
         return (c >= '0' && c <= '9');
    }
   public boolean isChar(char c) {
         return (c >= 'a' && c <= 'z');
     } 
    public String clearDigits(String s) {
      StringBuilder sb = new StringBuilder();
      for(char c : s.toCharArray()){
        int lastCharIndex = sb.length()-1;
        System.out.println(c);
         if(lastCharIndex >= 0 && isDigit(c) &&  isChar(sb.charAt(lastCharIndex))) {
            sb.deleteCharAt(lastCharIndex);
         } else{
            sb.append(c);
         }
      }
     return sb.toString(); 
    }
}
    

      /**

      "a234" :
      "aaa4":
      
      123
      bac123:
        c1 
        ba23 : 
        a2 
        b3 : 
        "" : 
       bac112 : 

  all digits possible..? only digits and no no-pdigit chars in string :
    Stack<Character > st= new Stack<>() ;


  boolean isChar(char c) {
      return (c >= 'a' && c <= 'z');
  }
  boolean isDigit(char digit) {
     return ((digit -'0' >= 0) && (digit -'0' <= 9));
  }
     for( char c : s) {
          if(!st.empty() || isChar(s.peek())){
               s.pop();
          } else{
            st.push(c);
          }
     }
     

    string ar immutable so can't use directly ; 
    even size alos not fixed : how much will reamins ans how much will be delted : 
    so use  string bufffer if want to do wihtout stack and use buffered string as stack and operations : 
  

    ---------------
     count appproach : using varibles only : 


       */  
    