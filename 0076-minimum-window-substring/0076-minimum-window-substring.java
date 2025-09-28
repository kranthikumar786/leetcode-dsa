class Solution {
    public String minWindow(String s, String t) {
        if (s == null || t == null || s.length() < t.length()) {
            return "";
        }

        int sLen = s.length();
        HashMap<Character, Integer> tFre = new HashMap<>();
        for (char ch : t.toCharArray()) {
            tFre.put(ch, tFre.getOrDefault(ch, 0) + 1);
        }

        int required = tFre.size();
        int minLen = Integer.MAX_VALUE;
        int leftPtr = 0, rightPtr = 0, start = 0;
        HashMap<Character, Integer> sFre = new HashMap<>();
        int formed = 0;

        while (rightPtr < sLen) {
            char ch = s.charAt(rightPtr);
            sFre.put(ch, sFre.getOrDefault(ch, 0) + 1);

            if (tFre.containsKey(ch) && sFre.get(ch).intValue() == tFre.get(ch).intValue()) {
                formed++;
            }

            // Try to shrink the window
            while (formed == required) {
                if (rightPtr - leftPtr + 1 < minLen) {
                    minLen = rightPtr - leftPtr + 1;
                    start = leftPtr;
                }

                char leftChar = s.charAt(leftPtr);
                sFre.put(leftChar, sFre.get(leftChar) - 1);

                if (tFre.containsKey(leftChar) && sFre.get(leftChar) < tFre.get(leftChar)) {
                    formed--;
                }
                leftPtr++;
            }
            rightPtr++;
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
    }
}

/**
class Solution {
    public String minWindow(String s, String t) {
       int sLen = s.length();
       int tRequired = t.length();
       HashMap<Character,Integer>tFre = new HashMap<>();
       for(char ch : t.toCharArray()) {
             int preFre = tFre.getOrDefault(ch,0);
             tFre.put(ch,preFre+1);
       } 
      HashMap<Character,Integer>sFre = new HashMap<>();
      int leftPtr =  0;
      int rightPtr = 0;
      int fomred = 0;
      while(rightPtr < sLen) {
            char ch = s.charAt(rightPtr);
            int PreFre = sFre.getOrDefault(ch,0);
            sFre.put(ch,PreFre+1);
           if(tFre.conatins(ch) && tFre.get(ch) == sFre.get(ch)) {
                   fomred++;
           }
             while(fomred == tRequired && rightPtr < sLen) {
                   minLen = Math.max(minLen,rightPtr-leftPtr+1);
                   char leftChar = s.charAt(leftPtr);
                   int fre = sFre.get(leftChar);
                   sFre.put(leftChar,fre-1);
                   if(sFre.get(leftChar) ==0 ){
                       sFre.remove(leftChar);
                   } 
                   leftPtr++;
             }
           rightPtr++;  
      }
    }
}
 */