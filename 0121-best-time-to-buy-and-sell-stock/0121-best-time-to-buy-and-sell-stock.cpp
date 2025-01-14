class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int profit = 0 , n = prices.size() ;
           if( n == 1) { return 0;}
           int left = 0 , right = 1 , max1 = prices[0];
               while(right  < n) {
                if(prices[left] > prices[right]){
                   profit = max(profit , max1 - prices[left]) ;
                   max1 = prices[right];
                   left = right;
                 }
                if(prices[right] > max1) {
                   max1 =  prices[right];
                  }
               right++;    
               } 
profit = max(profit , max1 - prices[left]) ;
         return profit;
    }
};


/*


 vector<int>suffixMax(n, 0) ;
         suffixMax[n-1] = prices[n-1];
           int  j = n-2 ;
            while(j >= 0) {
             suffixMax[j] = max(suffixMax[j+1] , prices[j]);
             j--;
            }
            for(int i = 0 ; i < n ;i++) {
                 ans = max(ans , suffixMax[i] - prices[i]);  
            }
  1, 2,200, 4,5,6,7,300 : 
 

 
 
 20 , 1, 200 , 300, 400, 5,600 : 
 
 20 , ....................... 600  looking for max : but meanwhile found min  then update:
   profit till now : 
    update min too 
    update max tooo :  

  int profit = 0 ; 
  int leftptr = 0 . rightPtr = 1 , max1 = 0; 
   


      found min value : 


 p = 0 , max1 = a[0]; 
 l = 0 , r = 1 ;
20 , 1, 200 , 300, 400, 5,600 : 

20 , 10, 200 , 300, 400, 5, 600,700 :



       while ( right < n) {
         if(nums[left] > nums[right]){
       profit = max(profit , max1 - nums[left]) ;
       max1 = nums[right];
       left = right;
       }
     if(nums[right] > max1) {
        max1=  nums[right];
     }
      right++;
}

    profit = max(profit , max1 - nums[left])


 

     


*/


   /*
        
         naive approach  :
           tc : O(n*n)) : 
           sc : O(1)
           ------------------
           approach 2:
            tc : O(n) + o(n)
            sc  :O(n): 
           rightside  max elment :
              [7, 1 , 5, 3 ,4 ,6 ] 
               7 , 6 , 6 ,6 ,6 ,6 
                               
      logic : 
               [7,6,4,3,1]
                7,6,4,3,1
              come fro right side : 
               suffixA[n-1] = A[n-1]:
                  while (j >= 0 ) {
                   suffixA[j] = max(suffixA[j+1], A[j]);
                       j--;
                  }           
        */