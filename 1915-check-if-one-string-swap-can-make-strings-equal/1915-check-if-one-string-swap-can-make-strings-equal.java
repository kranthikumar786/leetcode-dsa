class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
       int n = s1.length(), first = -1, second = -1;
     for(int i = 0 ; i < n;i++) {
         if(s1.charAt(i) != s2.charAt(i)){
              if(first == -1){
                 first = i;
              } else if(second == -1) {
                  second = i;
              }else{
                return false;
              }
         }
     }
     if(first == -1){
         return true;
     }
    return  (second != -1 && s1.charAt(first) == s2.charAt(second) && s1.charAt(second) == s2.charAt(first)); 
    }
}
      /**
       Order mattter , so hashing not helpful : 
        
        from ex 1: 
          s1 = "bank" , s2 = "kanb" 
  use two pointer i , j 
    if(i == j)
    {
        i++;j++;
    }
     else {
        find s1[i] , in s2[j+1 ...n] 
           svae = j indx : 

           if(s[j+1...n] = s[i])
             then swap s1[save] = s1[j]: , and compare two string are same or not . 
     }
        */ 