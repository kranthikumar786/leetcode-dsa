class Solution {
    public int numSub(String s) {
        int n = s.length();
        //int leftPtr = 0, rightPtr = 0;
        long ans = 0;
        int mod = 1_000_000_007;
      int streak = 0;
      for(char ch : s.toCharArray()){
            if(ch == '1'){
                   streak++;
                ans = (ans +streak)%mod;
            } else{
                streak = 0;
            }
      }
        // while(rightPtr < n) {
        //     if(s.charAt(rightPtr) == '0') {
        //         int l = rightPtr - leftPtr;
        //         if(l > 0){
        //            long sub = (1L*l * (l+1)/2)%mod;
        //            ans = (ans + sub)%mod;   
        //         }
        //         leftPtr = rightPtr+1;
        //     }
        //     rightPtr++;
        // }
        //      int l = rightPtr - leftPtr;
        //         if(l > 0){
        //            long sub = (1L*l * (l+1)/2)%mod;
        //            ans = (ans + sub)%mod;   
        //         }
         return (int)ans;       
    }
}
/**

/**
        "0 1 1 0 1 1 1 "
         0 1 2 3 4 5 6 : 

      int cnt = 0;
      int leftPtr = 0 , rightPtr = 0;
       int  n = s.length();
       while(rightPtr < n) {
            if(s.charAt(rightPtr) == '0') {
                int l = rightPtr - leftPtr;
                int sub = (l * (l+1))/2;
                cnt += sub ; 
                leftPtr = rightPtr;    
            }  
            rightPtr++;
       }
               int l = rightPtr - leftPtr;
                int sub = (l * (l+1))/2;
                cnt += sub ; 
     return cnt;


-----------------------------
int cnt = 0;
    int n = s.length();
     for(int i = 0 ; i < n ; i++) {
            int scnt = 0;
            for(int j = i ; j < n ;j++) {
                   if(s.charAt(j) == '1'){
                        scnt++;
                   } else {
                     break;
                   }
            }
            System.out.println(i+ " "+scnt);
            cnt += (scnt * (scnt+1)/2);
     }
 */