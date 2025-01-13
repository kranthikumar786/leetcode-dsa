class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
          int ans = 0 ;
          int sum = 0 ;
         int  n = nums.size();
    unordered_map<int,int>mp;
       for(int curPtr = 0 ; curPtr < n ; curPtr++) {
            sum += nums[curPtr];
             if(sum == k) {
                 ans++;
             }
           if(mp.find(sum-k) != mp.end()){
            ans += mp[sum-k];
           }
          mp[sum]++;
         
            //   while(leftPtr < curPtr && sum > k ) {
            //     sum -= nums[leftPtr];
            //      if(sum == k){
            //         ans++;
            //      }
            //      leftPtr++;
            //   }
       }
      return ans; 
    }
};

        /*

[-1,-1,1] : 
k == 0 :


-1 -1  +1 : 
-1 -1 +1 : 
  but if i take hre -1 + 1 = 0 : 

-2 != 0 
 -2 < 0 
 -1 < 0 {

 }



[1,1,1,-1,0,9,0,-1,20]

k = 3 : 

10 9 8 7 6 5 4 3 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 

[1,1,1,-1,0,9,0,-1,20]

 1  +1 + 1 = 3 : 
  1 + 1 + 1 -1 = 2 
  1 + 1 + 1 -1  +0  = 2

1 + 1 + 1 -1  + 0 + 9  = 11 : 

  1 , 1, 1 , -1 ,  0 , 9 = 



k = 3 :

ex : 1 
Out : 4 



        --------------------
[1,1,1]

 1 + 1 = 2 :
 2 > 2 : 


        
        [1,2,3] k = 3 : 

      1 + 2 = 3 : 
        1 + 2 + 3  >  3 : 
         remove left side : 

           2  +3  > 3 
            3  == 3 : 
              ans ++ ;

         now move to ritight wards : 
             3 + 0 = 3 , 
             3 + 0 -20 = -17 
             3, 0 , -20 , 20 == 3 : 
              ans ++ ;
             3 , 0, -20 ,20 , 1 :  4 > 3 : 

              0 -20 + 20 +1  < 3 : 



        */
      
      // generate all subarray and check : 


      /*
       2* 10^4 * 2 *10^4 = 4* 10^8 : 
        TLE :  
      */  