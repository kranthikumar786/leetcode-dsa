class Solution {
public:
    vector<long long> segmentTree;
    
    void buildSegmentTree(int index, int leftPtr, int rightPtr, vector<int>& nums) {
        if(leftPtr == rightPtr) {
            segmentTree[index] = nums[leftPtr];
            return;
        }
        int mid = (leftPtr + rightPtr) >> 1;
        buildSegmentTree(2*index+1, leftPtr, mid, nums);
        buildSegmentTree(2*index+2, mid+1, rightPtr, nums);
        segmentTree[index] = segmentTree[2*index+1] + segmentTree[2*index+2];
    }
    
    long long query(int sIndex, int left, int right, int Qleft, int Qright) {
        if(Qright < left || Qleft > right) {
            return 0;
        }
        if(Qleft <= left && right <= Qright) {
            return segmentTree[sIndex];
        }
        int mid = (left + right) >> 1;
        long long leftV = query(2*sIndex+1, left, mid, Qleft, Qright);
        long long rightV = query(2*sIndex+2, mid+1, right, Qleft, Qright);
        return leftV + rightV;
    }
    
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        segmentTree.resize(4 * n);
        buildSegmentTree(0, 0, n-1, nums);
        
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int left = i, right = n-1, best = i-1;
            while(left <= right) {
                int mid = (left + right) >> 1;
                long long sum = query(0, 0, n-1, i, mid);
                int dist = mid - i + 1;
                if(sum * dist < k) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans += (best - i + 1);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<long long >segmentTree;
//    void buildSegementTree(int index, int leftPtr, int rightPtr,vector<int>& nums){
//            if(leftPtr == rightPtr){
//                segmentTree[index] = nums[leftPtr];
//                return ;
//            }
//       int mid = (leftPtr + rightPtr) >>1;
//         buildSegementTree(2*index+1,leftPtr, mid,nums);
//        buildSegementTree(2*index+2,mid+1,rightPtr,nums);
//    segmentTree[index] = segmentTree[2*index+1]+ segmentTree[2*index+2]; 
//    }
// long long query(int sIndex,int left, int right,int Qleft,int Qright) {    
//       if(Qleft > right || Qright < left) {
//           return 0;
//       }
//       if(left <= Qleft && Qright <= right ) {
//           return segmentTree[sIndex];
//       }
//       int mid= (left + right)>>1; 
//      long long leftV = query(2*sIndex+1, left, mid,Qleft,Qright);
//      long long  rightV = query(2*sIndex+2, mid+1,right,Qleft,Qright); 
//     return leftV + rightV; 
// }
//     long long countSubarrays(vector<int>& nums, long long k) {
//        int n = nums.size();
//        segmentTree.resize(4*n,0);
//        buildSegementTree(0,0,n-1,nums);
//     long long ans = 0;
//        for(int i = 0 ;i < n ;i++) {
//            int left = i , right = n-1;
//             while(left <= right) {
//                  int mid = (left + right ) >>1;
//                  long long sum = query(0,0,n-1,left, mid);
//                    int dist = mid - left +1; 
//                   if((sum * dist)  < k){
//                         left = mid +1;
//                   } else{
//                     right = mid-1;
//                   }
//                  ans += (right-left +1) ; 
//             }
//        }
//       return ans;}
//     };    
//         // int n = nums.size();
      
//         // long long ans = 0;
//         // long long sum = 0;
//         // int leftPtr = 0;
//         // for (int rightPtr = 0; rightPtr < n; rightPtr++) {
//         //     sum += nums[rightPtr];
//         //     int dist = rightPtr - leftPtr + 1;
            
//         //     while (leftPtr <= rightPtr && (sum * dist) >= k) {
//         //         sum -= nums[leftPtr];
//         //         leftPtr++;
//         //         dist = rightPtr - leftPtr + 1;
//         //     }

//         //     ans += (rightPtr - leftPtr + 1);
//         // }

//         // return ans;
// //     }
// // };

// // class Solution {
// // public:
// //     long long countSubarrays(vector<int>& nums, long long k) {
// //         int n = nums.size();
// //         long long ans = 0;
// //    long long sum = 0;
// //     int leftPtr = 0 ;
// //     int rightPtr = 0;

// //       while(leftPtr < n ) {
// //          while(rightPtr < n ){
// //             sum += nums[rightPtr];
// //             int dist = rightPtr - leftPtr + 1;
// //             if((sum * dist) < k){
// //                 ans++;
// //             } else{

// //                  dist = rightPtr-leftPtr ;
// //                  ans += (dist);
// //                     rightPtr--;
// //                  leftPtr = rightPtr;
// //                  rightPtr--;
// //             }
// //          rightPtr++;
// //          }
// //       }
// //       return ans;
// // }
// // /*

// // //         sum -= nums[rightPtr];
// //             //   while(leftPtr < rightPtr ) {


// //             //   } 

// // */

// //     //         for(int j = 0 ; j < n ;j++) {
// //     //              long long  sum = 0;
// //     //              for( int k1 = j ; k1 < n ;k1++) {
// //     //                   sum += nums[k1];
// //     //                   int dist = k1-j+1; 
// //     //                    if((sum * dist) < k ){     
// //     //                      ans++;
// //     //                   } else{break;} 
// //     //                 //   if(sum * dist >= k ){
// //     //                 //      break;
// //     //                 //   } 
// //     //                    //cout<<(sum*dist)<<" \n";
// //     //                  //  cout<<(sum*dist)<<":"<<ans<<" \n";
// //     //              } 
// //     //          }
// //     //   return ans;
// //     // }
// // };
// // /*

// // // cout<<"\n"<<dist<<"\n";
// //                            //cout<<" ::\n"<<nums[k1]<<" \n";}
// //                     //   }else{
// //                     //      break;
// //                     //     // sum = 0; [2,1,4,3,5,1,1,1,1] : last 1,1,1,1 can be part of the ans for new subarray :
// //                     //   }
// // */