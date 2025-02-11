class Solution {
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
         */
 