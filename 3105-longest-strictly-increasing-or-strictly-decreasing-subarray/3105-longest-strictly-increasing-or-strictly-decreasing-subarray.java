class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n=nums.length;
        int res=1;
        int inc=1;
        int dec=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
            }
            else if(nums[i]<nums[i-1]){
                dec++;
                inc=1;
            }
            else{
                inc=1;
                dec=1;
            }
            res=Math.max(res,Math.max(inc,dec));
        }
        return res;
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