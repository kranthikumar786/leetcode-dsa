class Solution {
    public boolean isAlphaNumeric(char c) {
       return  Character.isLetterOrDigit(c);
    }
    public boolean isPalindrome(String s) {
        int leftPtr = 0 ;
        int rightPtr = s.length()-1;
           while(leftPtr < rightPtr) {    
                while(leftPtr < rightPtr && !isAlphaNumeric(s.charAt(leftPtr))) {
                       leftPtr++;
                }
                while(leftPtr < rightPtr && !isAlphaNumeric(s.charAt(rightPtr))) {
                        rightPtr--;
                }
              char leftChar = Character.toLowerCase(s.charAt(leftPtr));
              char rightChar = Character.toLowerCase(s.charAt(rightPtr));
              if(leftChar != rightChar) {
                 return false;
              }   
            leftPtr++;
            rightPtr--;  
        }
        return true;
    }
}