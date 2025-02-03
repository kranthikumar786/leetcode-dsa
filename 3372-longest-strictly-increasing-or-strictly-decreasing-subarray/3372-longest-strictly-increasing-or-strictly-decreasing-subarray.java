class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        if(n == 1) {return 1;}
         boolean isIncre =  false , isDecr = false;
     int j = 0 ;int  val = 1 ,ans = -1;;
     while (j < n -1) {
         if(!isDecr && nums[j] < nums[j+1]) {
                isIncre = true;
                 val++;
         } else if(!isIncre && nums[j] > nums[j+1]) {
              isDecr = true;
              val++;
         } else{ 
              isDecr = false;
              isIncre = false;
            ans = Math.max(ans,val);
           val = 1;
           if(nums[j] != nums[j+1]){
              j--;
           }
         }
         j++;
     } 
     ans = Math.max(ans,val);       
      return ans;     
    }
}
/**


[1,4,3,2,1] 
 1,4 :
 4,3,2,1 : 
 4 : 
for(int i = 0 ; i < n ;i++){
              int incre = 1,decres = 1;
              boolean in = false, de = false; 
             for(int j = i ; j < n -1; j++) {
                  if(nums[j] < nums[j+1] && !de) {
                       in = true;
                       incre++;

                  } else if(nums[j] > nums[j+1] && !in) {
                       de = false;
                       decres++;
                   }
                else if(nums[j] == nums[j+1]){
                      break;
                } else {
                    break;
                }   

             }
           ans = Math.max(incre,Math.max(decres,ans));  
        }

[1,2,3,4]

 [1,2,3,1,4,5,6,5,4,3,2,1,0,0]:
 
 two pininters :

  1 < 2 : 
  2 <3 : 
  3 <1  :

   1 < 4 
   4 < 5 
   5 < 6
   6 < 5 
   5 < 4 :  this is begingin yes :  so check for dec order :
 5 > 4 : 
 4>3
 2>3 
1 >2 
0> 1 :
 */