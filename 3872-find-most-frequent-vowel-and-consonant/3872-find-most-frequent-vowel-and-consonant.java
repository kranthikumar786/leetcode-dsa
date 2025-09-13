class Solution {
    boolean isVowel(char c){
        return (c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u' );
    }
    public int maxFreqSum(String s) {
       int vowelFre = 0;
       int consonantsFre = 0;
    HashMap<Character,Integer>hm= new HashMap<>();
    for(Character ch : s.toCharArray()) {
         int pre = hm.getOrDefault(ch,0);
         hm.put(ch,pre+1);
        if(isVowel(ch)){
            vowelFre = Math.max(vowelFre,pre+1);
        } else{
            consonantsFre = Math.max(consonantsFre, pre+1);
        } 
    }
    return vowelFre + consonantsFre;
    }
}