class Solution {
public:
    int maxProduct(vector<int>& nums) {     
       int maxV = INT_MIN;
       int prod = 1;
       for(int num : nums) {
          prod *= num;
            maxV = max(maxV,prod);
           if(prod == 0){
              prod = 1;
           }
       }
       prod = 1;
        for(int i = nums.size() -1 ;  i>= 0 ; i--){
         prod *= nums[i];
            maxV = max(maxV,prod);
           if(prod == 0){
              prod = 1;
           }       
        }
      return maxV;  
    }
};
/*
      [2,3,-1,4] : 
      
       2 * 3 = 6 : 
          
     if currProd = 0 : 
          currProd = 1;
          
         simply skip the window :
   */