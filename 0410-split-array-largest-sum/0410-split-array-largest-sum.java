class Solution {
     public boolean check(long maxSum , int[] nums, int k){
          int kCnt = 0;
          long localSum = 0;
           for(int n : nums){
                if((localSum + n) > maxSum) {
                      localSum = 0;
                      kCnt++;
                }
                localSum += n;
                //if(kCnt > k) return false;
           }
         return kCnt +1 <= k; 
     }
    public int splitArray(int[] nums, int k) {
     long l = Arrays.stream(nums).max().getAsInt();
     long r = Arrays.stream(nums).sum();
     long ans = -1; 
      while(l <= r){
          long m = l+ ((r-l)>>1);
          if(check(m,nums,k)){
            ans = m ; 
            r = m-1;
          }else{
            l = m+1;
          } 
      }
      return (int)ans; 
    }
}
/**
  int n = nums.length;
       int prefixSum[] = new int[n];
  
      [1,2,3,4,5] :
       1 3 6 10 15 : 
       
        for k = 2: 
        1  , [15-1] = 14:   14 is max: 
        3 , 15-3 : 12 :   here 12 is max : so now 12,14 = :12: 
        6 , 15-6 :  9 :    here 9 is max : so now 12,9 : 9 :  
        10 , 15-10 : 5 :  10 max here  : now min 9,10 : still 9  only answer:
   
   
     [1,2,3,4,5] : 
      
      n = 5: 
       k = 2: 
      [1,2]:[]: 
   */

     