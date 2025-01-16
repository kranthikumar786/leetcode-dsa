class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int n1 = nums1.length , n2 = nums2.length;
        int xor1 = 0 , xor2 = 0 , ans = 0;
        for(int i = 0 ; i < n1 ;i++){
            xor1 ^= nums1[i];
        }
       for(int i =0 ; i < n2 ; i++) {
        xor2 ^= nums2[i];
       } 
      if(n1%2 != 0){
        ans ^= xor2;
      } 
      if(n2%2 != 0){
        ans ^= xor1;
      }
   return ans;
    }
}