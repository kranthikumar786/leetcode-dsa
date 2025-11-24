class Solution {
   public  int BS(int[] nums, int t, boolean left){
         int index = -1;
          int l = 0 , r =nums.length-1;
           while(l <= r){
              int m= (l+r)>>1;
              if(nums[m] == t){
                  index = m;
                  if(left){
                    r= m-1;
                  }else{
                    l = m+1;
                  }
              } else if(nums[m] > t){
                  r = m-1;
              }else{
                l = m+1;
              } 
           }
         return index;   
    }
    public int[] searchRange(int[] nums, int t) {
        int ans[] = {-1,-1};
        int n = nums.length;
        if(n == 0 || nums[0] > t  || nums[n-1] < t) return ans;
        int first = BS(nums,t,true);// leftSide: 
        if(first == -1){return ans;}
        int last = BS(nums,t,false);
        ans[0] = first;
        ans[1] = last;
    return ans;
    }
}
/**
class Solution {
     this logic work only if : range value all are same : 
       but that is not the always scerniao: 

    public int[] searchRange(int[] nums, int t) {   
     if(nums.length ==0){return new int[]{-1,-1};}
      int index = -1;
      int l = 0, r= nums.length-1;
      int m = 0;
      int f = -1,s = -1;
       while( l <= r){
            m = (l+r)>>1;
           if(nums[m] == t){
              index = m;
               break;
           } else if(nums[m] < t){
                  l = m+1;
           } else{
              r = m-1;
           } 
       }
       if(index == -1){
        return new int[]{-1,-1};
       }  
      int rm = m;  
        while(l <= m ){
            int m1 = (l+m)>>1;
           if(nums[m1] == t){
             f = m1;
             r = m1-1;
           } else{
            l = m1+1;
           }       
        }
       while(rm <= r){
         int m1 = (rm+r)>>1;
        if(nums[m1] == t){
             s = m1;
            rm = m1+1; 
        }else{
            r = m1-1;
        } 
       }
     return new int[]{f,s};
    }
}

 */