class Solution {
public:
    vector<int> segTree;

    void buildSegmentTree(int index, int left, int right, vector<int>& nums, int maxEle) {
        if (left == right) {
            segTree[index] = (nums[left] == maxEle);
            return;
        }
        int mid = (left + right) >> 1;
        buildSegmentTree(2 * index + 1, left, mid, nums, maxEle);
        buildSegmentTree(2 * index + 2, mid + 1, right, nums, maxEle);
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    long long query(int index, int left, int right, int Qleft, int Qright) {
        if (Qright < left || Qleft > right)
            return 0;

        if (Qleft <= left && Qright >= right)
            return segTree[index];

        int mid = (left + right) >> 1;
        long long leftcnt = query(2 * index + 1, left, mid, Qleft, Qright);
        long long rightcnt = query(2 * index + 2, mid + 1, right, Qleft, Qright);
        return leftcnt + rightcnt;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        segTree.resize(4 * n, 0);
        int maxEle = *max_element(nums.begin(), nums.end());
        buildSegmentTree(0, 0, n - 1, nums, maxEle);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int left = i, right = n - 1;
            int best = -1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                long long cnt = query(0, 0, n - 1, i, mid);
                if (cnt >= k) {
                    best = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (best != -1) {
                ans += (n - best);  
            }
        }

        return ans;
    }
};




//  class Solution {
//  public:
//        vector<int >segTree;
//       void builldSegementTree(int index, int left, int right, vector<int>& nums, int maxEle){
//          if(left == right){
//             segTree[index] = (nums[left] == maxEle); 
//              return ;
//          }
//          int mid = (left+ right )>>1;
//           builldSegementTree(2*index+1,left, mid,nums,maxEle);
//           builldSegementTree(2*index+2,mid+1,right,nums,maxEle);
//          segTree[index] = segTree[2*index+1] + segTree[2*index+2] ;
//       }
//    long long  query(int index, int left,int right, int Qleft, int Qright){
//          if( Qright < left ||Qleft > right ){
//               return 0;
//          }
//          if(Qleft <= left  && Qright <= right){
//                return segTree[index];
//          }
//           int mid = (left + right )>>1;
//           long long   leftcnt = query(2*index+1,left, mid,Qleft, Qright);
//           long long  rightcnt = query(2*index+2,mid+1,right,Qleft, Qright);
//           return leftcnt + rightcnt;
//    }
//      long long countSubarrays(vector<int>& nums, int k) {
//        int n = nums.size();
//        segTree.resize(4*n,0);
//         int maxEle = *max_element(nums.begin(), nums.end());
//        builldSegementTree(0,0,n-1,nums,maxEle);
//            long long ans = 0;
//        for(int i = 0 ;i < n ;i++) {
//            int best = -1;
//           int left = i , right = n-1;
//           while(left <= right){
//                 int mid = (left + right )>>1;
//                 long long cnt = query(0,0,n-1,i,mid);
//                 if(cnt >= k){
//                     best = mid;
//                     right = mid-1;
//                  }else{
//                     left = mid+1;
//                   }
//           }
//           if(best != -1){
//               ans += (n- (best-i));
//           }  
//        }
//       return ans;  
//    }
// };






// // class Solution {
// // public:
// //     long long countSubarrays(vector<int>& nums, int k) {
// //         int n = nums.size();
// //         int maxEle = *max_element(nums.begin(), nums.end());
// //         long long ans = 0;
// //         int left = 0, count = 0;
// //         for (int right = 0; right < n; right++) {
// //             if (nums[right] == maxEle)
// //                 count++;

// //             while (count >= k) {
// //                 ans += (n - right); // all subarrays starting from left and ending from right to n-1 are valid
// //                 if (nums[left] == maxEle)
// //                     count--;
// //                 left++;
// //             }
// //         }
// //         return ans;
// //     }
// // };




// // // class Solution {
// // // public:
// // //     long long countSubarrays(vector<int>& nums, int k) {
// // //         int maxEle = *max_element(nums.begin(),nums.end());
// // //         unordered_map<int,int>um; 
// // //         int n = nums.size();
// // //         long long ans = 0;
// // //         int left = 0;
// // //         int right = 0;
// // //         for(int left = 0; left < n ; left++) {
// // //                while(right < n ) {
// // //                      if(maxEle == nums[right])
// // //                          um[maxEle]++;
// // //                       right++;  
// // //                      if(um[maxEle] >= k){
// // //                         ans++;
// // //                       }  
// // //               }

// // //            if(maxEle == nums[left])
// // //                 um[maxEle]--;
                     
// // //         if(um[maxEle] >= k){
// // //               ans++;
// // //             }
// // //         }
// // //        return ans;
// // //     }
// // // };