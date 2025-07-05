class Solution {
    public int findLucky(int[] arr) {
      HashMap<Integer,Integer>frequncy = new HashMap<>();
      for(int num : arr) {
        int numFre = frequncy.getOrDefault(num,0);
        frequncy.put(num,numFre+1);
      }

      int lucky_integer = -1;
      for(int key : frequncy.keySet()) {
        if(frequncy.get(key) == key) {
          lucky_integer = key;
       }
    }
   return lucky_integer;
    }
}