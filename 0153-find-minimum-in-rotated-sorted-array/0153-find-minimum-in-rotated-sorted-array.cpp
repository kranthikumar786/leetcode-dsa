class Solution {
public:
    int findMin(vector<int>& nums) {
     int n = nums.size() ;
     int left = 0 ,right = n-1 ,mid = 0;
       while(left < right) {
             int mid = (long(right) + left)>> 1 ;
            if(nums[mid] <= nums[n-1]) {
                  right = mid;
               } else{
                 left = mid+1;
               }
       }
       return nums[left];
    }
};    
   /*
   
   mid = ((long)right + left)>>1;
            if(mid -1 >= 0 && nums[mid-1] <=  nums[mid] && mid +1  < n  && nums[mid] > nums[mid+1]) {
                   return nums[mid+1];
            } 
             // now moving left possiblirity : 
            else if(mid -1 >= 0 && nums[mid-1] <=  nums[mid] && mid +1  < n  && nums[mid] < nums[mid+1]){
                     right = mid-1;
// //    [1, 2, 3, 4, 5]
//         0 1  2  3  4    


            }
             // moving right possiblities : 
             else{
                left = mid +1;
             }
       }
     case 1:  left side 
     case 2 : right side : 

     [3, 4 ,5 , 1, 2]

      mid = 5 : 
       now check it;s adjacents : 

    1 . rightSide answer : 
        4 < 5  && 5 > 1 : 
         one possiblitity : 
          that nums[mid+1] : is answer
      -------------------
    2.   leftSide answer present: 
        [1,2,3,4,5]  : 
           3 : 
          2 < 3 && 3 < 4 : 
             already in sequnce  order so move  searching sope to  left side : 
          [1,2,3] : 
      [1,2,3]  :
         1 < 2 && 2 < 3 : 
       now searching space moved to again left due to  proper order : 

        right = mid -1  : 
      [1,2] : 
       1/2 :  0 : 
       
         edge case 
     3 .  if(left > right) {
          return nums[mid] ; // answer :
      }
   */

/*
        basic idea of BS is  : 
   [1,2,3,4,5,6] : 
    0 1 2 3 4 5 
  5/ 2 = 2 :
    if(nums[0]  > k || nuums[n-1] < k) {
           return -1; 
    } 
          int left = 0 ,right = n-1 ;
            while (left <right){
                 int mid =  long (right + left )>>1;
                   if(nums[mid] == k) {
                      return mid;
                   } else if(nums[mid] > k) {
                     right = mid -1 ;
                   } else{
                     left = mid +1;
                   } 
            }
             return -1; // not found : 
     Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
          

     */
