class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String concatenated = s + s;
        return concatenated.substring(1, concatenated.length() - 1).contains(s);
    }
}
        
        /**
           s = "abcabcabcabc" 
                a
                   ab 
                      abc : 
                          abcabcabc :
   -----------------------------
       aba : 
        a:
          ab:
           end of condtion : return (substringnot reached the lenght  || or originl stirng not reached the  length)         
        */