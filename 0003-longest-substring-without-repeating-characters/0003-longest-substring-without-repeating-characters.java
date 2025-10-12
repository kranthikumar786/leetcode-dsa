class Solution {
    public int lengthOfLongestSubstring(String s) {
      HashSet<Character>hs = new HashSet<>();
      int leftPtr = 0 , rightPtr = 0;
      int n = s.length();
      if(n ==0 ){return n;}
       int ans = 1;
      while(rightPtr < n) {
        char ch = s.charAt(rightPtr);
         while(leftPtr < rightPtr && hs.contains(ch)) {
            ans = Math.max(ans,rightPtr - leftPtr);
            hs.remove(s.charAt(leftPtr));
            leftPtr++;
         } 
        hs.add(ch); 
        rightPtr++;
      }
         ans = Math.max(ans,hs.size());
      return ans;  
    }
    /* 

    // au : missed TC:
      a b c a z e
       
  
    */
}