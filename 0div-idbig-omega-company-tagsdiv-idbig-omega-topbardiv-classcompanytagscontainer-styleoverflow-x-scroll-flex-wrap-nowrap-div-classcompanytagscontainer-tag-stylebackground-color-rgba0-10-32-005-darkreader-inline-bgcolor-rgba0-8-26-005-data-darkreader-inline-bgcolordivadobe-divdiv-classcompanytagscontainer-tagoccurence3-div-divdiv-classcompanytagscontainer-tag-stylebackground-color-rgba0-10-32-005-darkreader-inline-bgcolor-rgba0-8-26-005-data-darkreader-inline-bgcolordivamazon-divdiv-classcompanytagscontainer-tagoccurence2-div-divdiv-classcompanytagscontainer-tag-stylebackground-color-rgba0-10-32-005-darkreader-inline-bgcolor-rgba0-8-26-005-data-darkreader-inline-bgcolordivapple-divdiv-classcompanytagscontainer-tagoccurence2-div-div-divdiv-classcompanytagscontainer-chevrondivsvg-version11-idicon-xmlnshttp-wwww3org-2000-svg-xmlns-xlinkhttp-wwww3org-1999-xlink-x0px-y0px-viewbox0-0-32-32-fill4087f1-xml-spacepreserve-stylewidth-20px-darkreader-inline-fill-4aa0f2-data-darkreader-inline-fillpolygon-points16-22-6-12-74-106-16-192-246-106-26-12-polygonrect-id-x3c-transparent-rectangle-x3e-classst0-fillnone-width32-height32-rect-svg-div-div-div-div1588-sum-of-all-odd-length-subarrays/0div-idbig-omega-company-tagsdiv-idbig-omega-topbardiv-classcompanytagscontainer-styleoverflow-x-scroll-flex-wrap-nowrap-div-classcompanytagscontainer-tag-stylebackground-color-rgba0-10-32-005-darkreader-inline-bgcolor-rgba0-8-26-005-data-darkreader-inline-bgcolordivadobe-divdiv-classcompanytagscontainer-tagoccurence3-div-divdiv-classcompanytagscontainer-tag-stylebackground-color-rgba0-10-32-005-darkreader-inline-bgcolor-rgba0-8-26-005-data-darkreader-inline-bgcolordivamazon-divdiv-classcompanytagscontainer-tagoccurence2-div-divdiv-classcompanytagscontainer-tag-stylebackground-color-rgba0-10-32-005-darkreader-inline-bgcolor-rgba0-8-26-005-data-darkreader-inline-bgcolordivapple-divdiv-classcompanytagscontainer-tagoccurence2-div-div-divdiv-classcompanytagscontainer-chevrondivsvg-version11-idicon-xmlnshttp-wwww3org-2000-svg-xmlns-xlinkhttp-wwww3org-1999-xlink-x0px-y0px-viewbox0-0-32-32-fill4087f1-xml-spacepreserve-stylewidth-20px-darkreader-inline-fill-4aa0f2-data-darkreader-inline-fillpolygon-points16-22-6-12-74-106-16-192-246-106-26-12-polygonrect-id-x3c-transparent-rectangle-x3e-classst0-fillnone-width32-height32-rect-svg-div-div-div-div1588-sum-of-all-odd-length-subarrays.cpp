class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
     int sum = 0 ;
     
        int n = arr.size();
      
      for(int i = 0 ; i < n ; i++) { 
          int  k = ((i+1)*(n-i) + 1)/2;
          sum += k*arr[i];
      }  
        
      /*
       from where and how this  (i +1) * (n - i) + 1 / 2 came 
       
Here one clarity is some how i have to use contribution only... but how ..? 
Single element  contubution in subarry(s) then even length subarry(s) and odd length subarray(s)

  Consider the subarray that contains A[i],
if we can take 0,1,2..,i elements on the left , from A[0] to A[i],then we have i + 1 choices on left side
if we can take 0,1,2..,n-1-i elements on the right,from A[i] to A[n-1], then we have n - i choices.

In total, there are k = (i + 1) * (n - i) subarrays, that contains A[i].
And there are (k + 1) / 2 subarrays with odd length, that contains A[i].
And there are k / 2 subarrays with even length, that contains A[i].

A[i] will be counted ((i + 1) * (n - i) + 1) / 2 times for our question.

what if Question modified to even length ..?  

  sum += k/2*A[i];

      */          
        /*
        for(int i = 0; i < n ;i++) {
            int localSum = 0;
             for(int j = i ; j < n; j++) {
                 localSum += arr[j];
                 if((j - i + 1)%2)   
                     sum += localSum; 
             }
        }
        */
        return sum;
    }
};