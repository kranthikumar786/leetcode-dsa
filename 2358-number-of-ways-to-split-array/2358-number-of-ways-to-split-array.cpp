class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       long long leftSum = 0 ; long long totalSum = 0 , noOfValidSplits = 0;;
      for(int num : nums) {
       totalSum += num; 
      }
       int n = nums.size();
     for(int numIndex = 0  ; numIndex < n-1 ; numIndex++){
         leftSum += nums[numIndex] ;
         totalSum -= nums[numIndex] ;
        if(leftSum >= totalSum) {
              noOfValidSplits++;
          }
     }
    return noOfValidSplits;
 }
};





    /*
        [10,4,-8,7] :
           10 >= 4 -8 + 7 = > 10 >= 3 
           Leftsum > = rightSum ;
                count++;

      10 + 4  >= -8 +7 : 
       14 > = -1 :
          count++;

          10 + 4 + -8 > = 7
           6 > = 7 : 
            false : 
    
    
    
    =========================
    
      specil case for sum (+ operaor) [ 0 , 0 ,0 , 0 , 0 , 0 ,0  ]
     0 > = 0 : 
maxValidSpilts = legnth of an array :  [ 0 , 0 ,0 , 0 , 0 , 0 ,0  ]
minValidSplits = 0; [1,2,4,8,16]
    
    */



   