class Solution {
    public int firstUniqChar(String s) {
       HashMap<Character,Integer>fre = new HashMap<>();
      for(char ch : s.toCharArray()) {
        int preFre = fre.getOrDefault(ch,0);
        fre.put(ch,preFre+1);
      }  
     for(int i = 0 ; i < s.length(); i++) {
          if(fre.get(s.charAt(i)) == 1){
            return i;
          }
     }
     return -1; 
    }
}