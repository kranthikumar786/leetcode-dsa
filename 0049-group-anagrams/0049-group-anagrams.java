class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
      HashMap<String,List<String>>group = new HashMap<>();
      int n = strs.length;
      for(String s : strs) {   
          char arr[] = s.toCharArray();
          Arrays.sort(arr);
          String key = new String(arr);
        group.computeIfAbsent(key,k->new ArrayList<>()).add(s);
      }
     return new ArrayList<>(group.values()); 
    }
}