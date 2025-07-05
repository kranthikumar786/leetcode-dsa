class Solution {
    public int findLucky(int[] arr) {
      HashMap<Integer,Integer>frequncy = new HashMap<>();
      for(int num : arr) {
        int numFre = frequncy.getOrDefault(num,0);
        frequncy.put(num,numFre+1);
      }

int ans = -1;
for (Map.Entry<Integer, Integer> fr : frequncy.entrySet()) {
    if (fr.getKey().equals(fr.getValue())) {
        ans = Math.max(ans, fr.getValue());
    }
}
   return ans;
    }
}