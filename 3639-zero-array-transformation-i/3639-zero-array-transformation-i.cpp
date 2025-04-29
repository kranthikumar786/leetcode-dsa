class Solution {
public:
    vector<int> segTree;
    vector<int> lazy;

    void buildSegmentTree(int index, int left, int right, vector<int>& nums) {
        if (left == right) {
            segTree[index] = nums[left];
            return;
        }
        int mid = (left + right) >> 1;
        buildSegmentTree(2 * index + 1, left, mid, nums);
        buildSegmentTree(2 * index + 2, mid + 1, right, nums);
        segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
    }

    void updateRange(int index, int left, int right, int l, int r, int val) {
        if (lazy[index] != 0) {
            segTree[index] -= lazy[index];
            if (left != right) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        if (r < left || l > right) return;

        if (l <= left && right <= r) {
            segTree[index] -= val;
            if (left != right) {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            return;
        }

        int mid = (left + right) >> 1;
        updateRange(2 * index + 1, left, mid, l, r, val);
        updateRange(2 * index + 2, mid + 1, right, l, r, val);
        segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
    }

    int queryMax(int index, int left, int right, int l, int r) {
        if (lazy[index] != 0) {
            segTree[index] -= lazy[index];
            if (left != right) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        if (r < left || l > right) return 0;

        if (l <= left && right <= r) return segTree[index];

        int mid = (left + right) >> 1;
        int leftMax = queryMax(2 * index + 1, left, mid, l, r);
        int rightMax = queryMax(2 * index + 2, mid + 1, right, l, r);
        return max(leftMax, rightMax);
    }

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        segTree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildSegmentTree(0, 0, n - 1, nums);

        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int val = 1;
            updateRange(0, 0, n - 1, l, r, val);
        }

        return queryMax(0, 0, n - 1, 0, n - 1) <= 0;
    }
};



// class Solution {
// public:
//       vector<int>segTree;
//       vector<int>Lazy;

//     void UpdateChange(int index, int left, int right, int Qleft, int Qright, int val) {
//           if(lazy[index] != 0){
//              segTree[index] += (right-left +1) * lazy[index];
//                if(left != right ){
//                   lazy[2*index+1] += lazy[index];
//                   lazy[2*index+2] += lazy[index];
//                }
//             lazy[index] = 0;   
//           }
//           if(Qright < left ||Qleft > right){
//                return ;
//           }
//           if(Qleft < = left && Qright >= right){
//             segTree[index] = (right-left +1) * val;
//               if(left != right){
//                 lazy[2*index+1] += val;
//                 lazy[2*index+1] += val;  
//               }
//           }
//           int mid = (left + right)>>1;
//           UpdateChange(2*index+1,left, mid, Qleft, Qright,val);
//           UpdateChange(2*index+1, mid+1,right, Qleft, Qright,val);
//           segTree[index] = max(segTree[2*index+1],segTree[2*index+2]);
//     }  
//     int Query(int index, int left , int right , int Qleft, int Qright){
//            if(lazy[index] != 0){
//              segTree[index] += (right-left +1) * lazy[index];
//                if(left != right ){
//                   lazy[2*index+1] += lazy[index];
//                   lazy[2*index+2] += lazy[index];
//                }
//             lazy[index] = 0;   
//           }
//           if(Qright < left ||Qleft > right){
//                return 0 ;
//           }
//           if(Qleft < = left && Qright >= right){
//             return segTree[index];
//           }
//              int mid = (left + right )>>1;
//            int leftMax = Query(2*index+1, left, mid,Qleft, Qright);
//            int rightMax = Query(2*index+2,mid+1,right,Qleft, Qright);
//              return max(leftMax, rightMax);
//     }
//     bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//           int n = nums.size();
//           segTree.resize(4*n,0);
//           buildSegementTree(0,0,n-1,nums);
//           lazy.resize(4*n,0);
//          for(auto query : queries) {
//               int left =qury[0];
//               int right = query[1];
//               int val = query[2];
//               UpdateChange(0,0,n-1,left,right,val);
//          }
//          for(int i = 0 ; i < n ;i++) {
//               int v = max(nums[i],)
//          }

//     }
// };

// // class Solution {
// // public:
// //     bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
// //         int n = nums.size();
// //         vector<int> diff(n + 1, 0);
// //         for (auto query : queries) {
// //             int left = query[0];
// //             int right = query[1];
// //             diff[left] += 1;
// //             if (right + 1 < n) 
// //             diff[right + 1] -= 1;
// //         }
// //         for (int i = 1; i < n; i++) {
// //             diff[i] += diff[i - 1];
// //         }
// //         for (int i = 0; i < n; i++) {
// //             if (diff[i] < nums[i]) {
// //                 return false;
// //             }
// //         }

// //         return true;
// //     }
// // };


// // // class Solution {
// // // public:
// // //     bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
// // //      int  n = nums.size();
// // //      vector<int>diff(n+1,0);
// // //            diff[0] = nums[0];
// // //        for(int i = 1; i < n; i++) {
// // //             diff[i] = nums[i] - nums[i-1];
// // //             //cout<<diff[i]<<"::";
// // //        }  
// // //        for(auto query : queries) {
// // //                int left = query[0];
// // //                int right = query[1];
// // //               diff[left] += 1;
// // //               diff[right+1] -=1 ; 
// // //        } 
// // //        for(int i = 1 ; i <= n ;i++) {
// // //             diff[i] = diff[i] + diff[i-1];
// // //             cout<<diff[i]<<":";
// // //        } 
// // //         for(int i = 0 ;i < n ;i++) {
// // //           if(diff[i] < nums[i]){return false;}
// // //         }
// // //  return true;
// // //     }
// // // };