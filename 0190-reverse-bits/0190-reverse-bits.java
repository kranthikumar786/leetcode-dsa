class Solution {
    public int reverseBits(int n) {
         int ans = 0;
         for(int i = 0 ; i < 32; i++) {
               ans <<= 1;
               ans |= (n&1);
               n = n>>1;  
         }
         return ans; 
         //return rev(n, 32); 
         }

    // private int rev(int v, int len) {
    //     if (len == 1) return v & 1;

    //     int half = len >> 1;
    //     int mask = (1 << half) - 1;
    //     int lo = v & mask;
    //     int hi = v >>> half;

    //     return (rev(lo, half) << half) | rev(hi, half);
    // }
}
