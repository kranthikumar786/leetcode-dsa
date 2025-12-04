class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
       HashSet<String>wordListSet = new HashSet<>(wordList);
       Queue<Pair<String,Integer>>Q = new LinkedList<>();
       Q.add(new Pair<>(beginWord,1));
       wordListSet.remove(beginWord);
       while(!Q.isEmpty()){
         Pair<String,Integer> p = Q.poll();
         String word = p.getKey();
         int level = p.getValue();
          if(word.equals(endWord)){
             return level;
          }
          char arr[] = word.toCharArray();
          for(int i = 0 ; i < arr.length;i++){
              char oChar = arr[i];
               for(char ch = 'a' ; ch <= 'z' ; ch++) {
                     arr[i] = ch;
                     String newWord = new String(arr);
                    if(wordListSet.contains(newWord)){
                        Q.add(new Pair<>(newWord,level+1));
                        wordListSet.remove(newWord);
                    }   
               }
             arr[i] = oChar;  
          } 
       }
      return 0;  
    }
}