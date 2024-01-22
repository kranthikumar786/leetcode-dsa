class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
     
     int twiceOccurence = 0,missingNumber = 0;
        int n = nums.size();
        int arr[ 10001] = {0};
       for(int  num : nums) {
           arr[num]++;
       } 
     for(int i = 1 ; i <= n ; i++) {
          if(arr[i] == 0) {
              missingNumber = i;
          }
          if(arr[i] == 2){
              twiceOccurence = i;
          } 
     }
    return {twiceOccurence ,missingNumber};    
        
        
        
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