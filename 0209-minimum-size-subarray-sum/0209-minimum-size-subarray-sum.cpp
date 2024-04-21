class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
       /*for(int i = 0 ; i < n ; i++) {
             sum  = 0;  
           for(int j = i ; j < n; j++) {
                 sum += nums[j];
                 if(sum >= target) {
                      f = 1;
                     minL = min(j - i +1, minL);
                 } 
            }
       }
       */
        
      //  return !f ? 0 : minL; 
        
        /*int sum = 0;
        [2,3,1,2,4,3]
        2 + 3 + 1 + 2  =8 
            3 + 1 + 2 + 4 =  10 
               1 + 2+ 4  = 7 : 
                   2 + 4 + 3 = 9 :         
           */
        
        
          int n = nums.size(); 
      int sum = 0 , minL = 1e9;
        
      deque<int>Q;
      
        for(int i = 0 ; i < n ; i ++) {
            sum += nums[i];
            Q.push_back(i);
            while( Q.size() && sum >= target) {
                minL = min(minL,  i - Q.front() + 1);
               sum -= nums[Q.front()];
                Q.pop_front();
            }  
        }
        /*
        int left = 0 , right = 0; 
         while (right < n ){
               sum += nums[right];
             while (sum >= target) {
                 minL = min(minL, right - left  +1);
                 sum -= nums[left];
                 left++;
             }
             right++;
         }
        */ 
        return minL == 1e9  ? 0 : minL;
        
      /*
      TC : O(n) 
      SC:0(1)
      */  
        
    /*
         [2,3,1,2,4,3]
        
         2 + 3 + 1 + 2  > t 
            break ;
       
          3 +1 + 2 + 4  > t ;
           1 + 2+4  == t : 
            min = 3 ;
           
          2 + 4 + 3 > t;
           4 + 3  = t 
               min = 2 :
      
        Tc : O(n*n)
        SC : 0 (1);    
        
        */
    /*
    Worst TC & Best SC : 
      11 
      1 1  1 1 1 1 1 1 1 1 1 1
    
       Output : 11
       Expected : 11
    
    
   Avg TC & Best SC:   
    
    
    
    */    
        
    }
};