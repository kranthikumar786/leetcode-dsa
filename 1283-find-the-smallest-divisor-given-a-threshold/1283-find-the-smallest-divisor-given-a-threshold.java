class Solution {
     public boolean canMake(int div, int t , int[] nums){
            int sum = 0;
           for(int n : nums){
               sum += (n+div-1)/ div; 
           }
        return (sum <= t);   
     }
    public int smallestDivisor(int[] nums, int threshold) {
     int r = Arrays.stream(nums).max().getAsInt();
     int ans = -1;
     int l = 1;
      while( l <= r){
         int d = (l+r)>>1;
          if(canMake(d,threshold,nums)){
            ans = d;
            r = d-1;
          }else{
            l = d+1;
          }
      }
      
     //int n = nums.length;
    //  for(int i = 1 ; i <= maxEl ; i++) {
    //        int r1 = 0;
    //        for(int j = 0 ; j < n ; j++) {
    //             r1 += (nums[j] + i -1) / i;
    //        }
    //      //  System.out.println(r1 == 5 ? i : -1);
    //         if(r1 <= threshold){
    //             ans = i;
    //              break;} 
    //     //    if(r1 < threshold  && ans != -1){
    //     //       ans = r1;
    //     //    }   
    //  }
     return ans;
    }
}