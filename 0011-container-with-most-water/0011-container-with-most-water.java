class Solution {
    public int maxArea(int[] height) {
        int maxWater = 0;
        int left = 0; 
        int right = height.length - 1;
        
        while (left < right) {
            int dist = right - left;
            int minPoleH = Math.min(height[left], height[right]);
            maxWater = Math.max(maxWater, (minPoleH * dist));
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }  
        return maxWater;
    }
}

/**
for(int l = 0 ; l < n ;l++) {
           int ans = 0;
            for(int r = l+1; r < n; r++) {
                  int minV =  Math.min(height[l],height[r]) * (r-l);    
                 ans = Math.max(minV,ans);
            }
            maxWater = Math.max(maxWater,ans);
     }
 */