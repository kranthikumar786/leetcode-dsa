class Solution {
    public int findLucky(int[] arr) {
      HashMap<Integer,Integer>frequncy = new HashMap<>();
      for(int num : arr) {
        int numFre = frequncy.getOrDefault(num,0);
        frequncy.put(num,numFre+1);
      }

int lucky_integer = -1;
for (Map.Entry<Integer, Integer> fr : frequncy.entrySet()) {
    if (fr.getKey().equals(fr.getValue())) {
        lucky_integer = Math.max(lucky_integer, fr.getValue());
    }
}
   return lucky_integer;
    }
}