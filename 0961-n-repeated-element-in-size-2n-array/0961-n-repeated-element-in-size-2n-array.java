class Solution {
    public int repeatedNTimes(int[] nums) {
     HashSet<Integer>hs = new HashSet<>();
     for(int n : nums){
        if(hs.contains(n)){
            return n;
        }
        hs.add(n);
     }
     return 1;   
    }
}