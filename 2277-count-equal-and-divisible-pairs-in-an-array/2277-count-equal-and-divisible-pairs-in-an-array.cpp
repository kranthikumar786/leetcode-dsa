
class Solution {
public:
    bool isDivisiblebyK(int num , int k) {
          return (num%k == 0  ? 1 :  0);
    } 
     bool isSame(int num1 , int num2) {
          return num1 == num2;
     } 
    int countPairs(vector<int>& nums, int k) {
       int n = nums.size();
           if(n == 1){
             return 0;
        }
       int numberOfPairs = 0 ; 
       for(int i = 0 ;i < n ; i++) {
            for(int j = i +1; j < n ; j++ ) {
                  if(isSame(nums[i],nums[j]) && isDivisiblebyK(i*j,k)) {
                      numberOfPairs++;
                  } 
            }
       }
  return numberOfPairs;
   /*
     cleariffications: 
        1 < = numsSize <= 100 : 
         1 <= nums[i] , k  <= 100 
         co-relation b/w inputs: 
           alwys a pair exisng which is divisble by k ..? 
              divisiblity so check for 0 : 
              1 % 1 = 0 : but first pair should b presnet: 
         base case : if numsSize == 1 : return 0 : irespetive of k :

           i can be part of many pair with  j and j > i ..? yes: 

      countpairs = 0 : 
        [1 2 1 0,] k = 2: 
        0, 1,2,3
        1 1
         0 
       [1,1,1,1,1] : k = 2:
      output: 
       ans always exting : like 0 or more: 
       can fit in integet : reltaed to storage :

      Apprpoach : 
         1) hold i then look for j in right side which meet a[i] = A[j] && (i*j)%K ==0 
           tc :O(n*n) 
           sc : O(1)
   */
    }
};