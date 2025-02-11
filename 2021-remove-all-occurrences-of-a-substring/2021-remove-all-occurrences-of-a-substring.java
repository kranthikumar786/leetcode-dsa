class Solution {
    public String removeOccurrences(String s, String part) {
     StringBuilder str = new StringBuilder(s);
      while(str.indexOf(part) != -1 ) {
          int index = str.indexOf(part);
        str.delete(index, index + part.length());  
      } 
     return str.toString();
    }
}



/*class Solution {
    public String removeOccurrences(String s, String part) {
        
        StringBuilder str = new StringBuilder();
        int sl = s.length();
        int pL = part.length();
        for(int sIndex = 0 ;sIndex < sl ; sIndex++){ 
              str.append(s.charAt(sIndex));  
               if (str.length() >= pL) {
                if (part.equals(str.substring(str.length() - pL))) {
                    str.delete(str.length() - pL, str.length());
                }
            }}
       return str.toString(); 
   }
}
*/

        /**

s = "daabcbaabcbc"
p = zz :                not present substring so retrn complete string tc 
-----------------------
 s = "d"
 p = zz    length based tc : 
 -----


worst case tc remves alll substring and return empty : : 
aaaaaaaaa
a                 
----------


base case  singel cahrs present : as empty string are invalid inputs:
a
b

------------------
example 1 &2 are ggod check this probelm it self : 


--------


one beauftiful pattern  tc : 

s = aaaaabcbcbcbcbc : 
 p = abc



        -------------------
        daabcbaabcbc
        dabaabcbc
        dababc
        dab
        
        apporach  : 
         
         take string builder and add char by chay once size becoemd >= part size: 
           check last substring of size part is same as part or not , if yes remove substring :
           iteratively do it : 
         tc  :O(n^2) :  10^3 * 10^3 = 10^6 > 10^5 so TLE can be easily expected : 
         sc : O(n) :  
        abc 


----------------------------------------

   why stack is not best approach  ...? interms of implmentaion ..? 
     we can only check the vtop valuesusing peek() but at worst case we might need to have to check 
     10^3 size substring and at the end which might not be same last char from stack  so it kind of not best practice to write that code 
     so simply use strinBuilder as internally it will take care about all and we can move ahead with our core / required logic : 


pattern matching algo like KMP or other won't works here 
becuase of removing nature and after rmeve again can form the substring : 
  so won't work : 






         */
 