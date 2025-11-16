class Solution {
    public int trap(int[] height) {
        int  n  = height.length;
        int water = 0;
        int rightMax[] =  new int[n];
        
         rightMax[n-1] = height[n-1];
         for(int i = n-2 ; i >= 0;i--) {
            rightMax[i] = Math.max(rightMax[i+1],height[i]);
         }
         int leftMax = height[0];
        for(int i = 0 ; i < n ;i++) {
            leftMax = Math.max(leftMax,height[i]);    
            water += Math.min(leftMax,rightMax[i]) - height[i];
        } 
    return water;     
    }
}

/**


int leftMax[] = new int[n];
        int rightMax[] =  new int[n];
        leftMax[0] = height[0];
        for(int i = 1 ; i < n ;i++){
            leftMax[i] = Math.max(leftMax[i-1],height[i]); 
        }
         rightMax[n-1] = height[n-1];
         for(int i = n-2 ; i >= 0;i--) {
            rightMax[i] = Math.max(rightMax[i+1],height[i]);
         }
        for(int i = 0 ; i < n ;i++) {
            water += Math.min(leftMax[i],rightMax[i]) - height[i];
        } 

--------------------------------------------------

    int leftMax = 0;
             for(int j = 0 ; j <=i; j++){
                leftMax = Math.max(leftMax,height[j]);
             }
             int rightMax = 0;
             for(int k = i; k < n ;k++) {
                rightMax = Math.max(rightMax,height[k]);
             }
           water += Math.min(leftMax,rightMax) - height[i];



TLE 

int  n =height.length;
    int water = 0 ;
    for(int i = 0 ; i < n ;i++) {
           int max1 = 0;
           boolean f = false;
           for(int j = i+1 ; j < n ;j++) {
                  if(height[i] >= height[j]){
                      max1 +=(height[i]-height[j]);
                       f = true;
                  }else{
                    break;
                  }
           }
           if(f)
           water = Math.max(water,max1);
    }

*/