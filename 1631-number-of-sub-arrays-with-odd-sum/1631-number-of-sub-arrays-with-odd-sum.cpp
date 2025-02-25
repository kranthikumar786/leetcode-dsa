class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
    int Mod = 1e9+7;
    int ans =  0 ;
    int prefixSum = 0 ;
    int oddCount = 0 ,evenCount = 1;
    for(int num : arr) {
        prefixSum += num;
        if(prefixSum %2 == 0) {
               ans += oddCount;
               evenCount++; 
        } else{
            ans += evenCount;
            oddCount++;
        }
       ans %= Mod;
    }
 return ans;

    

        /*
        vector<int>oddFrequencyRightSide(n+1,0);
       for(int i = n-1 ;i >= 0 ; i--) {
           oddFrequency[i] = (arr[i]%2 ? (1 + oddFrequency[i+1]) :oddFrequency[i+1]);
       }
      int Mod = 1e9+7 ;
      int ans = 0 ;
      for(int i = 0 ; i < n ;i++) {
        ans = (ans + oddFrequency[i])%Mod;
      }  
return ans;


      
      
         tc : O(n^3)
         sc : O(1) : 


          

           contrubtion with 
           currently : if A[i] == odd : 
                        if A[i] == even : 
                        2+2 = 4 ALWAYS EVEN : 
                        2+3 = 5 : ODD : 
                        3+3 = EVEN  : 

                      SINGLE ELEMTNS ODD IS CONSDIED : 

                      THEN AFTER : 

                      ODD NUOF TIME OF ODD VALUE WILL BE CONSIDED : 

                      1, 3, 5 : 
                      1+3+5 = 9 : 
       


                 
                   1 : (2)
                     1 + 1 : 
                  1 , 3, 5 
                        
                        2*1 = 2 :


                    
                  1,3 ,5 : 
                            
                   LEFTSIDE HAS BEEN ALREADY USED : SO : 
                   USE ONLY RIGHT SIDE: 



          1 ,3 ,5 
          

         1: +1 : 
            3 
            1 : 
               5 
               1 : 

            

            SUB ARRAY STARTS WITH : I INDEX SO ALWSY CHOSE TO HAVE I ,(I+1, N ) NO.OF ELEMTS ARE ODD : 
            
         1 3 5 3 1  :
         5 4  3 2 1 
       
        1 2 3 4 5 3 1 
        5 4 4 3 3 2 1
       
        1 0 1  
        1 0 1



         1 1 1 1 1 :    
         1   1 

        */
    }
};