class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2,0);
        int n = nums.size();
      for(int i = 0 ; i < n ; i++) {
         int val = abs(nums[i]);
         ans[1] ^= (i+1)^val;
          if(nums[val -1] < 0) ans[0] = val;
          else nums[val -1] = - nums[val-1];
          
      }
    ans[1] ^= ans[0];
 return ans;

       
        
        
        
        
      /*  for(int i = 0 ; i < n ;i++ ) {
             bool f = 0 ; 
            for(int j = 0 ; j < n ; j++) {
                 
                   if(nums[j] == start) {
                       start++;
                        f = 1 ;
                       break;
                   }
             }
            if(f){
                break;
            } 
        }
        return {start , start+1}; 
        */
    }
    /*

   index and array..? like cyclic sort ..? 
   
   [1,2,2,4] : 
   
   1,2,2, 
   
   
   twice we can find :
    index = 0 ;
    
     1  =  arr[0] : 
     1 = 1 
     2 = 2 :
  if index +1   != arr[index] then missing values : 
Gathering Requriments : 

twicing and missing number may or may not be consective numbers : 
    input is not always sorted ..? No ,
    
    since 1 to n ranges ; so don't ask for  non-positve values follow up.
     
     
    */
};