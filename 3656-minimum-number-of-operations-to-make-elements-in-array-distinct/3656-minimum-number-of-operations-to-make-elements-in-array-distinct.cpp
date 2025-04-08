class Solution {
public:
    int minimumOperations(vector<int>& nums) {
  int n  = nums.size();
   //if(n < 3) {return 1;}
    // if(n%3 == 0){
   
    //     return ((n/3-1) + nums[n-3] );
    // }
     unordered_set<int>seen;
     for(int i = n-1; i >= 0 ; i--) {
          if(seen.find(nums[i]) == seen.end()) {
               seen.insert(nums[i]);
          }else{
            int f = i+1;
             return (f/3 + (f%3 !=0));
          }
     }
    return 0;        

   /**[1,2,3,4,2,3,3,5,7]
       
       1 ,2 ,3   :
            4, 2, 3, ,3 ,5,7: 

     
      priority_quuw: 
       fixed window size 3: 

       alwyas from beging only : 

       1,1,1,2, 3,4: 
  
    point here is let's have all unique values should be in +3 postion from it's another value :
      if mulple present : 

           
    [1, 2, 3, 4, 2, 3, 3, 5, 7]
     0  1  2   3  4  5 6  7  8 :

     sorting not ALLOWED ...? 

       IF(N%3 != 0) {
         EMPTY ARRAY POSSIBLITY}:

        IF(N%3 ==0 ) {EXACTLY TAKEN NO REMINDER:}

         
           ANS += (N/3); 
           ANS += N%3 != 0; 
   **/



    }
};