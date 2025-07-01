class Solution {
    public int possibleStringCount(String word) {

    int ans = 1; 
    int n = word.length();    
     for(int i = 1 ; i < n ;i++) {
         if(word.charAt(i-1) == word.charAt(i)){
             ans++;
         }
     }   
    return ans;          
        /**
        abb cc cc
          1 2 3 4 : 
        abbcccc : 
        abbc : 
        abbcc : 
        abbccc :
        abbcccc:
        abcccc: 
        abc is valid :
        
      abbc : 
        aaaa
        a 
        aa
        aaa
        aaaa :
         */
    }
}