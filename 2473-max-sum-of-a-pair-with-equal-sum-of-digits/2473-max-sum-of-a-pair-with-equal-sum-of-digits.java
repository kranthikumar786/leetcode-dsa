class Solution {
    public void digitSum(int []nums , int pre[]){
          int n = nums.length;
          for(int  i = 0 ; i < n ;i++){
               int digitSum = 0 ;
                int d = nums[i];
                while(d > 0){
                     digitSum += (d%10);
                      d = d/10; 
                }
             pre[i] = digitSum;    
          } 
    }
   public int maximumSum(int[] nums) {    
         int maxSum = -1;
          int n = nums.length;
         int pre[] = new int[n];
         digitSum(nums,pre);
Map<Integer, int[]> digitSumBasedMap = new HashMap<>();
 for(int i = 0 ; i < n ;i++) {
      int digitSum = pre[i];
      if(digitSumBasedMap.containsKey(digitSum)){
               int[] p = digitSumBasedMap.get(digitSum); 
               int num1 = nums[p[0]];
               int num2 = (p[1] == -1) ? Integer.MIN_VALUE : nums[p[1]];
             int current = nums[i];
             if (current > num1) { 
                    p[1] = p[0]; 
                    p[0] = i;
                } else if (current > num2) { 
                    p[1] = i;
                }
            if (p[1] != -1) {
                    maxSum = Math.max(maxSum, nums[p[0]] + nums[p[1]]);
                }
                } else {
                digitSumBasedMap.put(digitSum, new int[]{i, -1});
            }
 }
return maxSum;
//   for(int i = 0 ; i < n ; i++) {
//        int iSum = digitSum(nums[i]);
//       for(int j = i + 1; j < n ;j++) {
//            int jSum = digitSum(nums[j]);
//            if(iSum == jSum) {
//              maxSum = Math.max(maxSum, nums[i] + nums[j]);
//            }     
//       }
//   }
//   return maxSum ; 


//   Pair<Interg,Integer>P = digitSumBasedMap.getValue(digitSum);
//       if(p.first != -1 && p.second != -1) {
//       }
//        else if(p.second != -1){
//         maxSum = Math.max(maxSum , nums[p.first] + nums[i]);
//         p.second = i;  
//        }
//       }
//      else {
//         digitSumBasedMap.put(digitSum,digitSumBasedMap.put(digitSum, new int[]{i, -1}));
//      }  


   /**
 now thinkging of optmizations : 
------------------------------------------------------------------


class Solution {

    // public void digitSum(int []nums , int pre[]){
    //       int n = nums.length;
    //       for(int  i = 0 ; i < n ;i++){
    //            int digitSum = 0 ;
    //             int d = nums[i];
    //             while(d --> 0){
    //                  digitSum += (d%10);
    //                   d = d/10; 
    //             }
    //          pre[i] = digitSum;    
    //       } 
    // }

      public int digitSum(int n) {
         int digitSum = 0 ;
          while(n > 0){
                digitSum += (n%10);
                n = n/10; 
          }
         return digitSum; 
      }
    public int maximumSum(int[] nums) {    
         int maxSum = -1;
          int n = nums.length;
        //  int pre[] = new int[n];
        //  digitSum(nums,pre);

  for(int i = 0 ; i < n ; i++) {
       int iSum = digitSum(nums[i]);
      for(int j = i + 1; j < n ;j++) {
           int jSum = digitSum(nums[j]);
           if(iSum == jSum) {
             maxSum = Math.max(maxSum, nums[i] + nums[j]);
           }     
      }
  }
  return maxSum ; 





    tc : O(n*n*maxDigits)
    sc : O(1): 
     verdict can expecte TLE : 
 tc1 : [18,43,36,13,7,108]  imp test case  :  

        extening  like : 

  [18,43,36,3613,7,108] : 
   two time 36 coming so will consider first 36 or second 36 it is an optinalt for now : 



  tc3   asceinf order : 
   tc4 : desconig order :
   
    tc : 5 :  sinelg elemtne base case :  retuner -1 :
    tc : 6 : only two elemetns : equal and not equal cases for besat case : 

     not found in entire big list which is worst tc :

   tc 2 :

    */        
        /**
        digitSumArray : preprocessing : [9,7,9,13,7,9] :  tc : O(n*maxDigits):
                                         0 1 2 3 4  5
                        later approach :  O(n^2) :
                         two loops and this time avoiding the digtSum caluation in forloop : 
       -------------------------------------------

      map can help here...?  let say : digitsum :  and inideces list :
        ex : 9 - > 0 , 2 : 
        digit size matter here : exampele: 
          [18,43,36,13,7] = > [18,43,36,13,7,108]  : 
               36 + 108 gives max sum  with any indices.
               summmaaztion 0 places impoatnt role here:
               let's check with pair only like : if alreay exisint then check where it is bigger o not if not update the value : 
                    else keep same : 

             Map<Integer,Pair<Integer,Interger>M : 

              by default assign to pair value as -1 : 
            digitSum Based pair <> : 
             9 :  0,2:  = > get max value if two incidec presnet :  max value : and update : 
             7 :  1,4:  if contsina entire in if consiton and take value : check it :  
             13 : 3, -1
    in array number can be somthing like 10008 also possible so size of number like bigger number  matter her: 
               if(containsKey()){
                Pair<INT,INT>Pair= map.getValue(key);
                   if(Nums[pair.first] > nums[pair.second] && nums[pair.sconed] < nums[current_digitSum_Index]) {
                         maxSum = nums[pair.first] +  nums[currentindex_];
                         update pair second value with new indeicd: 
                        UpdateGloabl max Sum ; 
                   else if( nums[pair.seond] > nums[pair.first] && nums[pair.first] < nums[currentIndex]) {
                        maxSum = nums[pair.second] +  nums[currentindex_];
                       update pair first value with new indeicd: 
                        UpdateGloabl max Sum ; 
                   }      
                   }
               }  
---------------------------------------------
           Preocepseed : digitSumArray  : 
                          input array : 
               required DS :Map<Int, pait<int,int>>Map : 
         */
    }
}