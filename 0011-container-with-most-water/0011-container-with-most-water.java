class Solution {
    public int maxArea(int[] height) {
       int ans = 0;
        int n = height.length;
       int l = 0 ,r = n-1;
         while(l < r){
            int pol = Math.min(height[l],height[r]);
            int dist = r-l;
            ans = Math.max(ans, dist*pol);
           if(height[l] <= height[r]){
            l++;
           }else{
            r--;
           }
         }
         return ans;
      /**
       Approach 1: 
            fix one pole and look for another pole in all possible ways:
              using two loops:
               then calucate ans:
          TC: O(n^2):
          SC: O(1):     
        Approach 2: 
          dist is fine , looking for max eelmts , so eleimate min from etiher of left or right :
               and calc the ans:  
       */   
    }
}