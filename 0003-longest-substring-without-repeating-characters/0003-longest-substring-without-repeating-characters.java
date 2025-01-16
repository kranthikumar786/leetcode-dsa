class Solution {
    public int lengthOfLongestSubstring(String s) {

    
       int n = s.length();
    if(n == 0) { return 0;}
       int leftPtr = 0, rightPtr = 0;
       HashSet<Character>visited = new HashSet<>();
    int ans = 0 ;
    while(rightPtr < n) {
       while(visited.contains(s.charAt(rightPtr))){
          visited.remove(s.charAt(leftPtr));
          leftPtr++;
       }  
      ans = Math.max(ans, rightPtr - leftPtr); 
     visited.add(s.charAt(rightPtr));  
     rightPtr++;
    }
  return ans + 1;
    }
}