class Solution {
    public int finalValueAfterOperations(String[] operations) {

       int num = 0 ;
       for(String operation : operations) {
           //num += (operation.equals("++X") || operation.equals("X++")) ? 1 : -1; 
           num += (operation.charAt(1) == '+') ? 1:-1;
       }
   return num;
    }
}