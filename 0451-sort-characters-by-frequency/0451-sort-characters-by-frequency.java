class Solution {
    public String frequencySort(String s) {
      HashMap<Character,Integer>charFre = new HashMap<>();
      HashMap<Character,Integer>firstChar = new HashMap<>();
      for(int i = 0 ; i < s.length() ; i++) {
          char c = s.charAt(i);
         int prevF = charFre.getOrDefault(c,0);
         charFre.put(c,prevF+1);
         firstChar.putIfAbsent(c,i);
      }
      List<Character>allChars = new ArrayList<>(charFre.keySet());
      allChars.sort((a,b) ->{
          int fre = Integer.compare(charFre.get(b),charFre.get(a));
          if(fre != 0) return fre;
          return Integer.compare(firstChar.get(a),firstChar.get(b)); 
      });

     StringBuilder str = new StringBuilder();

      for(Character ch :  allChars){
        int fre = charFre.get(ch);
        str.append(String.valueOf(ch).repeat(fre));  
      }
      return str.toString();
    }
}