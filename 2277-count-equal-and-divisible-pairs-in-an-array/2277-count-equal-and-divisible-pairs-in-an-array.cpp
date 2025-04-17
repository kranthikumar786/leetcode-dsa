
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
      unordered_map<int,vector<int>>valuemapWithIndices(101);
   for(int i = 0 ; i < n ;i++) {
        valuemapWithIndices[nums[i]].push_back(i); 
        }
      for(int i = 0 ;i < n ;i++) {
           for(auto second : valuemapWithIndices[nums[i]]) {
                 if( i != second && isDivisiblebyK(second * i , k)) {
                     numberOfPairs++;
                 }
           }
          valuemapWithIndices[nums[i]].erase(valuemapWithIndices[nums[i]].begin());
          // valuemapWithIndices[nums[i]].pop_front();  
           // this will O(n) time : 
      }
      //return numberOfPairs;
    //   
    //    for(int i = 0 ;i < n ; i++) {
    //         for(int j = i +1; j < n ; j++ ) {
    //               if(isSame(nums[i],nums[j]) && isDivisiblebyK(i*j,k)) {
    //                   numberOfPairs++;
    //               } 
    //         }
    //    }
  return numberOfPairs;

 /*
   optimzation thoughts: 
     
      if i just have to check right side max elemt then i would have used stack  to get and solve: 
        here is matching  values right side : i can easily get indix and  nums[index] : 
            by storing index then automaticllay get value as well : 


        innerloop is finding right side same value : 
            : stack, sliding wondow, two pointers , hasmap : 
            : stack won't help here: 

             need two indices : 

               3 ------- 3: 
                  
                  1 ,2,2,2 ,1 : 
                  if simply an elment : match , i would have store the frequncy in then match : 
                left = 0 ,right = 0 ;
                  while(left <= right) {
                        while(right < n ){
                            hm[3] = 2: 
                            hm[1] = 2: 
                            hm[2] = 3:  
                              ans += hm[3]/2 ; 1 :  
                        }


                  }





                  for the best case :  




 
 
 */



   /*
     clarifications: 
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
   
   ==============================================
  code review: 
   Readability : proper naming convesion for varible and functions : 
   Modulized : Yes: 
   Maintinability : Modulized the code so yes: 

   */
    }
};
/*
==========================================================
 Improvement Part:
bool isDivisiblebyK(int num , int k) {
          return (num%k == 0 );
    }
 Approach : 
     for each pair(i,j)  with j > i :
          check if nums[i] == nums[j] && 
          check if i *j % k  == 0
              numberOfPairs++;     

  Evalution Parameters: 
     Time Compexity  :O(n^2)
     Space Complexity : O(1):
    Test Cases : 
            edge case : 
                     if input size == 1 then  return 0 :                                  
            Max pairs testcase  : 
                     [1,1,1,1,1] : k = 2 (even):

            worst case with numberOfPairs  = 0; 
                        [1,2,3,4,5 ]  k = 3 (odd) or  k = 2 (even)  
                        numberOfPairs = 0 ;
            Best case with numberOfPairs  = 0;
                      edge case : if input size == 1 then  return 0 : 
*/