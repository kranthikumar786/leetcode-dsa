class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        long long sum = 0;
        int leftPtr = 0;

        for (int rightPtr = 0; rightPtr < n; rightPtr++) {
            sum += nums[rightPtr];
            int dist = rightPtr - leftPtr + 1;
            
            while (leftPtr <= rightPtr && (sum * dist) >= k) {
                sum -= nums[leftPtr];
                leftPtr++;
                dist = rightPtr - leftPtr + 1;
            }

            ans += (rightPtr - leftPtr + 1);
        }

        return ans;
    }
};

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, long long k) {
//         int n = nums.size();
//         long long ans = 0;
//    long long sum = 0;
//     int leftPtr = 0 ;
//     int rightPtr = 0;

//       while(leftPtr < n ) {
//          while(rightPtr < n ){
//             sum += nums[rightPtr];
//             int dist = rightPtr - leftPtr + 1;
//             if((sum * dist) < k){
//                 ans++;
//             } else{

//                  dist = rightPtr-leftPtr ;
//                  ans += (dist);
//                     rightPtr--;
//                  leftPtr = rightPtr;
//                  rightPtr--;
//             }
//          rightPtr++;
//          }
//       }
//       return ans;
// }
// /*

// //         sum -= nums[rightPtr];
//             //   while(leftPtr < rightPtr ) {


//             //   } 

// */

//     //         for(int j = 0 ; j < n ;j++) {
//     //              long long  sum = 0;
//     //              for( int k1 = j ; k1 < n ;k1++) {
//     //                   sum += nums[k1];
//     //                   int dist = k1-j+1; 
//     //                    if((sum * dist) < k ){     
//     //                      ans++;
//     //                   } else{break;} 
//     //                 //   if(sum * dist >= k ){
//     //                 //      break;
//     //                 //   } 
//     //                    //cout<<(sum*dist)<<" \n";
//     //                  //  cout<<(sum*dist)<<":"<<ans<<" \n";
//     //              } 
//     //          }
//     //   return ans;
//     // }
// };
// /*

// // cout<<"\n"<<dist<<"\n";
//                            //cout<<" ::\n"<<nums[k1]<<" \n";}
//                     //   }else{
//                     //      break;
//                     //     // sum = 0; [2,1,4,3,5,1,1,1,1] : last 1,1,1,1 can be part of the ans for new subarray :
//                     //   }
// */