class Solution {
 public:
     long long numberOfSubarrays(vector<int>& nums) {
             long long ans = 0 ;
            int n = nums.size();
             vector<int>counter(n,1);
             stack<int>st;
             for(int i = 0 ; i < n ;i++) {
                  while(!st.empty() && nums[st.top()] <= nums[i]) {
                        if(nums[st.top()] == nums[i]){
                              counter[i] = 1 + counter[st.top()]; 
                        }
                       st.pop(); 
                  }
                  st.push(i);     
             }
        return accumulate(counter.begin(),counter.end(),0LL);
      }
};




// class Solution {
//  public:
//      long long numberOfSubarrays(vector<int>& nums) {
//        long long ans = 0 ;
//        int leftptr = 0 ;
//        int rightptr =  0;
//        int n = nums.size();
//       for(int i = 0 ; i< n ;i++) {
//            for(int j = i ; j < n ;j++){
//                if(nums[i]== nums[j]){
//                    ans++;
//                }
//                if(nums[j] > nums[i]){
//                   break;
//                }
//            }
//       } 
//   return ans ;
//      }
//      };




//  /*
//  6,26,6
//  1  1  1
//         // st.push(nums[0]);
//    for(int i = 0 ; i < n ; i++) {
         
//           while(!st.empty() && st.top() < nums[i] ) {
//                   st.pop();
//           }
         
//         st.push(nums[i]);
//         ans += (st.size() * (st.size()+1))/ 2; 

//    }
 
//   st.top() < nums[i] : pop elemt : 6 removed : 26 pushed: 

//     26 < 6 :




// */

// // class Solution {
// // public:
// //     long long numberOfSubarrays(vector<int>& nums) {
// //       long long ans = 0 ;
// //       int leftptr = 0 ;
// //       int rightptr =  0;
// //       int n = nums.size();
// //       while(leftptr < n && rightptr < n ){
// //             if(nums[leftptr] != nums[rightptr]){
// //                  int totalsize = rightptr - leftptr ;
// //                  ans += (totalsize*(totalsize+1))/2;
// //                 leftptr = rightptr;
// //             }
// //              rightptr++;
// //       }
// //       int totalsize = rightptr - leftptr ;
// //         ans += (totalsize*(totalsize+1))/2;
// //      return ans; 
// //         /*

// //           30 , 15, 30 : 
  
// //        got it , look for same elemt is okay , but what about less values ..? 
// //         i missed it : 
        

// //              3 3 4 3  
                   
// //         [1,4,3,3,2]
// //          1,4,1: this is not into ans:           
// //           first elemt is max elemt : if you found max then currnt then break : 
// //        3 3 3 3 3 4 4 
// //        i       j  
// //           n * (n+1) /2 
// //           2 * 3 / 2  = 6/ 2   : 3: 
// //           alwys update i == j : 

// //           no of subrayy forms with given this size: 


// //         */
// //     }
// // };