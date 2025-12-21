class Solution {
    public int maxScore(int[] cardPoints, int k) {
       int lS = 0 , rS = 0 , ans = 0;  
      int n = cardPoints.length;
      for(int i = 0 ; i < Math.min(k,n); i++){
        lS+= cardPoints[i];
      } 
       if(k == n) return lS;
      for(int j = n-k ; j < n ;j++){
        rS+= cardPoints[j];
        }
        System.out.println(lS);
        System.out.println(rS);

       ans = Math.max(lS,rS);
       System.out.println(ans); 
    int l = 0 , r = n-k;
      while(r < n ){
         rS-= cardPoints[r++];
         rS+= cardPoints[l++]; 
        ans = Math.max(ans,rS);   
        System.out.println(rS);
      }
     return ans; 
    }
}