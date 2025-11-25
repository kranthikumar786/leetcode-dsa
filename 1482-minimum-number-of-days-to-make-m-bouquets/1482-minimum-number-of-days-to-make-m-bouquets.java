class Solution {
    public boolean canMake(int day, int[]arr, int k, int m){
         int mTime = 0;
         int kAdj = 0;
          for(int f: arr){
              if(f <= day){
                   kAdj++;
                    if(kAdj == k){
                       mTime++; 
                        kAdj = 0; 
                    }
              } else{
                kAdj = 0;
              }
             if(mTime == m) return true;  
          }
         return mTime >= m; 
    }
    public int minDays(int[] arr, int m, int k) {
     if((long)m*k > arr.length) return -1;
     int l  = Arrays.stream(arr).min().getAsInt();
     int r  = Arrays.stream(arr).max().getAsInt();
     int ans = -1;
      while(l <= r) {
          int d = (l+r)>>1;
          if(canMake(d,arr,k,m)){
            ans = d;
            r = d-1;
          }else{
            l = d+1;
          } 
      }
     return ans;  
    }
}