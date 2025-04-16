class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                same += cnt[nums[right]];
                ++cnt[nums[right]];
            }
            if (same >= k) {
                ans += n - right;
            }
            --cnt[nums[left]];
            same -= cnt[nums[left]];
        }
        return ans;
    }
};


// class Solution {
// public:
//     long long countGood(vector<int>& nums, int k) {
//         long long ans = 0;
//         int n = nums.size();
        
//         for (int i = 0; i < n; ++i) {
//             unordered_map<int, int> freq;
//             long long pairs = 0;
            
//             for (int j = i; j < n; ++j) {
//                 pairs += freq[nums[j]]; // each existing num[j] forms a pair
//                 freq[nums[j]]++;
                
//                 if (pairs >= k) {
//                     ans++;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };







// class Solution {
// public:
//     long long countGood(vector<int>& nums, int k) {
//      long long ans = 0 ;
//      long long matches = 0; 
//      int n = nums.size() ;
//      for(int i = 0; i < n ;i++) {
//           unordered_set<int>s;
//            s.insert(nums[i]);
//            //matches = 0;
//           for(int j = i +1; j < n;j++) {
//              cout<<nums[j]<<" ";
//              if(s.find(nums[j]) != s.end()){
//                    matches++;
//              } else{
//                 s.insert(nums[j]);
//              }
//             if(matches >= k){
//                 ans++;
//             } 
//           }
//           s.clear();
//      }
//  return ans;
  /*
   nums = [1,1,1,1,1], k = 10
            1 (4) : 
             1 (3) : 
              1  (2)  : 
                1 ( 1) : 
                10 : 
  nums = [3,1,4,3,2,2,4], k = 2

              [3,1,4,3,2,2]     1:  2 APIRS:  
              [3,1,4,3,2,2,4}   1: 3 APIRS: 

                STORE THE 3 IN UNORDER_SET: 
                  3 LOOPS: 
                   HOLD LEFTMOST VALUE : 
                    TO SEARCH FOR A[I] == A[j] : in subsrray : 

                                [3,1,4,3,2,2,4]

                                  3  1 4 3    : matcg = 1: 
                                           2 2 : match = 2: 
                                              4:     
                    

                             1 4 3 2 2 4 :   3 as an goodcoount: 


                          4 3 2 2 4 :   

    tc : O(n*n) : 
    sc : O(n) : 

 suffixcount :
   
   3 2 4 3 2 2 4 : 
   2 3 2 1 2 1 1:
   
  



   3    2   4   3   2   2   4 : 
 {2,x}  3   2   1   2   1    1:

   simply number and index also impo : 
    if it could have been some number then okay : 





  


    where it is goig to end also imp: 
       
    set : 4  : frequnce :  
        : 2:
          3:       
 3    2   4   3   2   2   4 :
 1    1   1   2   2   3   2 : 


 3 -2 : 
 2- 3: 
 4 - 2: 


  for(int j) 

   for(int i = 0 ; i < n ;i++) {
        
        
        
        unorder_map<int,int> :   
 
   }
                          for(int j = 0 ; j < n ; j++) {
                               set.eraseall():
                            for(int k = j ; k < n ;k++) {
                                 
                                  if(set.find(nums[k])!= set.end()) {
                                     set.insert(nums[k])
                                  } else{
                                      matches++;
                                      if(goddcount >= k) {
                                        goddsubarrys++;
                                      }
                                  }
                                
                            }
                          }
                     }
          3 3   = 1: 
          1 = 0: 
          4  4 = 1: 
          3 = 0 : 
          2 2  = 1: 
          4     = 0 :  
  */      
//     }
// };