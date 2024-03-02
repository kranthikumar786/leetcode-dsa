class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        /* This approach is Accepted but , we can do better then this interm of wroting code / logic as well
        int minIndex = 0 , minValue = 10001;
      for (int i = 0 ; i < n ; i++) {   
          if(abs(nums[i]) < abs(minValue)) {
              minValue = nums[i];
              minIndex = i;
          }
          
          if(abs(nums[i]) > abs(minValue)){
               break;
          }
      }    
        //cout<<minIndex<<minValue;
     int leftPointer = minIndex , rightPointer = minIndex + 1 ;
     while (leftPointer >= 0 && rightPointer < n) {
            
           if(abs(nums[leftPointer]) < abs(nums[rightPointer])) {
                   ans.push_back(nums[leftPointer] * nums[leftPointer]);    
                leftPointer--;
           } else {
               ans.push_back(nums[rightPointer] * nums[rightPointer]);
               rightPointer++;   
           }
     }
       while(leftPointer >=0 )  {
            ans.push_back(nums[leftPointer] * nums[leftPointer]);
            leftPointer--;
       }
     
        while (rightPointer < n ) {
            ans.push_back(nums[rightPointer] * nums[rightPointer]);
            rightPointer++;
        }
        */
        
       int leftPointer = 0 , rightPointer = n -1 ;
       int  currentIndex = n - 1 ; 
        while (leftPointer <= rightPointer) {
             if(abs(nums[leftPointer]) >= abs(nums[rightPointer])) {
                 ans[currentIndex--] = nums[leftPointer] * nums[leftPointer++] ;
                 
             } else {
              ans[currentIndex--] = nums[rightPointer] * nums[rightPointer--] ;   
             }  
          } 
      return ans;  
    }
};

/*
Dry RUN : IS DONE 
Test cases : 

[-4,-1,0,3,10] = pass : given test case:
[-7,-3,2,3,11] = > pass : given test case : 

[1,2,3,4,5] = > pass : increaing order 
[1,1,1,2,2] = > non-decrasing order 
[5,4,4,3,3] = > pass non-incraing order  invalid test case : 
[]


*/
