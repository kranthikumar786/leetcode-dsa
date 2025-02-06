class Solution {
    public int tupleSameProduct(int[] nums) {
        int ans = 0;
        int n = nums.length;
        if (n < 4) {
            return 0;
        }
        Map<Integer,Integer>map = new HashMap<>();
        for(int index1 = 0 ; index1 < n ; index1++) {
              for(int index2 = index1+1; index2  <n ; index2++) {
                 int mul = nums[index1]*nums[index2];
                 if(map.containsKey(mul)){
                    ans += (8* map.get(mul)); 
                 }
                 map.put(mul,map.getOrDefault(mul,0)+1);
              }
        }
        return ans;
    }
}

   /**
   10^4 * 10^4 *10^4 *10^4  = 
   bases are == then add powers :
   4 +4 +4 +4 = 16 : 
   10^16 : easily TLE :

       Naive approach : 
       aIndex, bIndex, cIndex,dIndex : 
       and go for logic : 

        */ 
