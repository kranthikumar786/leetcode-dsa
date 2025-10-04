class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<Character, String> fre = new HashMap<>();
        HashSet<String> usedWords = new HashSet<>();
        String words[] = s.trim().split("\\s+");
        if (pattern.length() != words.length) return false;
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);
            String word = words[i];
            if (fre.containsKey(ch)) {
                if (!word.equals(fre.get(ch))) {
                    return false;
                }
            } else {
                if (usedWords.contains(word)) {
                    return false;
                }
                fre.put(ch, word);
                usedWords.add(word);
            }
        }
        return true;
    }
}
/**

class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<Character,String>fre = new HashMap<>();
        String words[] = s.split(" ");
        if(pattern.length() != words.length){
            return false;
        }
       for(int i = 0 ; i < pattern.length() ;i++) {
             String word = words[i];
            if(fre.containsKey(s.charAt(i)) && !word.equals(fre.get(s.charAt(i)))) { 
                     return false;
            }
            fre.put(s.charAt(i),word);  
       }
       return true; 
    }
}
 */