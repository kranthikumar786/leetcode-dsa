class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character,Integer>hm = new HashMap<>();
        if(s.length() != t.length()) return false;
        
        for(char ch : s.toCharArray()){
           int preF = hm.getOrDefault(ch,0);
          hm.put(ch,preF+1);   
        }
        for(char ch : t.toCharArray()) {
           int preF = hm.getOrDefault(ch,0);
           if(preF == 0){return false;}
             hm.put(ch,preF-1);
             if(hm.get(ch) == null || hm.get(ch) == 0) {
                   hm.remove(ch);
             }
        }
       return hm.isEmpty();  
    }
}