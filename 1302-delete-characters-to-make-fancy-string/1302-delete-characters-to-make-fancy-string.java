class Solution {
    public String makeFancyString(String s) {
      StringBuilder str = new StringBuilder();
      int n = s.length();
     for(int i = 0 ; i < n ;i++) {
        if(i+1 < n && i + 2 < n && 
           s.charAt(i) == s.charAt(i+1)  && 
           s.charAt(i+1) == s.charAt(i+2)) {
             str.append(String.valueOf(s.charAt(i)).repeat(2));
             while(i +1 < n  && s.charAt(i) == s.charAt(i+1)) i++;
        } else{
            str.append(s.charAt(i));
        }
     }
     return str.toString(); 
    }
}
/**

  str.append(s.charAt(i)).repeat(2);  
   */