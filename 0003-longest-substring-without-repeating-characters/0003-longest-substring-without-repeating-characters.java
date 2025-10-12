class Solution {
    public int lengthOfLongestSubstring(String s) {
     HashMap<Character,Integer>charAtIndex = new HashMap<>();
      int leftPtr = 0 , rightPtr = 0;
      int ans = 0;
      int n = s.length();
      while(rightPtr < n) {
        char  ch = s.charAt(rightPtr);
        if(charAtIndex.containsKey(ch)) {
           leftPtr = Math.max(leftPtr,charAtIndex.get(ch)+1);  // this is jump, not slisding window
        }
       charAtIndex.put(ch,rightPtr);
        ans = Math.max(ans,rightPtr-leftPtr+1);
        rightPtr++;  
      }
    return ans;
    }
}