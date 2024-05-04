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