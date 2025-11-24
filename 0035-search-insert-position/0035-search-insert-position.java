class Solution {
    public int searchInsert(int[] nums, int t) {
     if(nums[0] > t){return 0;} 
     int r = nums.length-1;
     if(nums[r] < t) {return r+1;}
     int l = 0;
     //int p = 0 ;
       while(l <= r ){
            int m = l + ((r-l)>>1);
           if(nums[m] == t) return m;
            else if(nums[m] > t){
                //p = m;
                r = m-1;
            }else{
               // p = m;
                l = m+1;
            }
       }
       return l;
    }
}