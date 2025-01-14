class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int ans = 0 , n = prices.size() ;
           if( n == 1) { return 0;}
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
         return ans;
    }
};

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