class Solution {
    public List<String> stringMatching(String[] words) {
          int totalWords = words.length;
          List<String> ans = new ArrayList<>();
          HashSet<String>s = new HashSet<>();
          for(int word = 0 ;word < totalWords;word++) {
               String eachWord = words[word];
               for(int sword = 0 ; sword < totalWords ; sword++ ) {
                       if(word != sword && eachWord.length() <= words[sword].length()) {
                         if(words[sword].contains(eachWord)) {
                            s.add(eachWord);
                         }  
                       }
               }
          }
          ans.addAll(s);
          return ans;
    }
}

// BF 