class Solution {
    public boolean isAlphaNumeric(char c) {
       return  Character.isLetterOrDigit(c);
    }
    public boolean isPalindrome(String s) {
        int leftPtr = 0 ;
        int rightPtr = s.length()-1;
           while(leftPtr < rightPtr) {    
            if(Character.toLowerCase(s.charAt(leftPtr)) == Character.toLowerCase(s.charAt(rightPtr))) {
                   leftPtr++;
                   rightPtr--;
                   continue;
            }
            if(!isAlphaNumeric(s.charAt(leftPtr))) {
               leftPtr++;
            } else if(!isAlphaNumeric(s.charAt(rightPtr))) {
                 rightPtr--;
            } else{
                return false;
            }
        }
        return true;
    }
}