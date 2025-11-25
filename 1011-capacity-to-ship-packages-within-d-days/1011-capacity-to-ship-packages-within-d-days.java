class Solution {
    public boolean canMake(int weight,int[] weights, int days){
         int daysCnt = 1;
         int weightSum = 0;
        for(int w: weights){
            if(weightSum + w > weight){
                  daysCnt++;
                 weightSum = 0; 
            }
           weightSum +=w;
          if(daysCnt > days){return false;}   
        }
       return true;  
    }
    public int shipWithinDays(int[] weights, int days) {
      int l = Arrays.stream(weights).max().getAsInt();
      int r = Arrays.stream(weights).sum();
      int ans = r;
       while( l <= r ){
          int weight = (l+r)>>1;
         if(canMake(weight,weights,days)){
              ans = weight;
               r = weight-1;
         } else{
            l = weight +1;
         }
       }
     return ans;
    }
}
/**
class Solution {
    boolean canMake(int weight, int[] weights, int days){
        int daysCnt = 0;
        int weightSum = 0;
        for(int w : weights){
            weightSum += w;
            if(weightSum > weight){
                daysCnt++;
                weightSum = w;
            }     
        }
       return  daysCnt <= days;
    } 
    public int shipWithinDays(int[] weights, int days) {
      int l = 1;
      int r = Arrays.stream(weights).sum(); 
      int ans = r;
       while(l <=r ){
          int weight = (l+r)>>1;
         if(canMake(weight,weights,days)){
            ans = weight;
            r = weight-1;
         }else{
            l = weight+1;
         } 
       }
       return ans; 
    }
}
 */