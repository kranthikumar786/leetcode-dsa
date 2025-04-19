class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
      int n = nums.size();
      long long ansCountFairPairs = 0;
      sort(nums.begin(),nums.end());
         for(int i = 0 ;i < n ;i++) {
             int left = i + 1;
    auto low = lower_bound(nums.begin()+left, nums.end(), lower-nums[i])-nums.begin();
    auto high = upper_bound(nums.begin()+left, nums.end(), upper-nums[i])-nums.begin();         
             ansCountFairPairs += (high-low);
         }
       return ansCountFairPairs;

    //  for(int i = 0; i < n ;i++){
    //       for(int j = i +1; j < n ;j++) {
    //             int sum = nums[i] + nums[j]; 
    //              if(sum >= lower && sum <= upper){
    //                 ans++;
    //              }
    //       }
    //  }

     //  sort(nums.begin(),nums.end());
    /*[0,1,7,4,4,5]
       0 1 2 3 4 5 

       0 1 4 4 5 7   l = 3 , u = 6: 
       




         0 1 4 4  5  
          
       5 0    0  + 5  
       5 1    0 + 4 
       5 4    0 +4





          5 0 
          5 1 
          5 4 

 
      
            


      */   

    // return ans;
    }
};