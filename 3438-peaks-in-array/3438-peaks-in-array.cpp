class Solution {
public:
    vector<int> segmentTree;
    vector<int> nums;

    int isPeak(int index) {
        if (index == 0 || index == (int)nums.size() - 1) return 0;
        return (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]) ? 1 : 0;
    }

    void buildSegmentTree(int segIndex, int left, int right) {
        if (left == right) {
            segmentTree[segIndex] = isPeak(left);
            return;
        }
        int mid = (left + right) >> 1;
        buildSegmentTree(2 * segIndex + 1, left, mid);
        buildSegmentTree(2 * segIndex + 2, mid + 1, right);
        segmentTree[segIndex] = segmentTree[2 * segIndex + 1] + segmentTree[2 * segIndex + 2];
    }

    void update(int segIndex, int left, int right, int idx) {
        if (left == right) {
            segmentTree[segIndex] = isPeak(left);
            return;
        }
        int mid = (left + right) >> 1;
        if (idx <= mid) {
            update(2 * segIndex + 1, left, mid, idx);
        } else {
            update(2 * segIndex + 2, mid + 1, right, idx);
        }
        segmentTree[segIndex] = segmentTree[2 * segIndex + 1] + segmentTree[2 * segIndex + 2];
    }

    void UpdatePoint(int value, int index, int segIndex, int left, int right) {
        nums[index] = value;
        update(segIndex, left, right, index);
        if (index - 1 >= 0) update(segIndex, left, right, index - 1);
        if (index + 1 < (int)nums.size()) update(segIndex, left, right, index + 1);
    }

    int Query(int segIndex, int Qleft, int Qright, int left, int right) {
        if (Qright < left || Qleft > right) return 0;
        if (Qleft <= left && right <= Qright) return segmentTree[segIndex];
        int mid = (left + right) >> 1;
        int leftResult = Query(2 * segIndex + 1, Qleft, Qright, left, mid);
        int rightResult = Query(2 * segIndex + 2, Qleft, Qright, mid + 1, right);
        return leftResult + rightResult;
    }

    vector<int> countOfPeaks(vector<int>& num, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = (int)num.size();
        segmentTree.assign(4 * n, 0);
        nums = num;
        buildSegmentTree(0, 0, n - 1);

        for (auto& query : queries) {
            if (query[0] == 1) {
                int leftBound = query[1] + 1;
                int rightBound = query[2] - 1;
                if (leftBound > rightBound) {
                    ans.push_back(0);
                } else {
                    int result = Query(0, leftBound, rightBound, 0, n - 1);
                    ans.push_back(result);
                }
            } else {
                UpdatePoint(query[2], query[1], 0, 0, n - 1);
            }
        }
        return ans;
    }
};





















// class Solution {
// public:
//     vector<int> segmentTree;
//     vector<int> nums;

//     int isPeak(int index) {
//         if (index == 0 || index == nums.size() - 1) return 0;
//         return (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]);
//     }

//     void buildSegmentTree(int segIndex, int left, int right) {
//         if (left == right) {
//             segmentTree[segIndex] = isPeak(left);
//             return;
//         }
//         int mid = (left + right) >> 1;
//         buildSegmentTree(2 * segIndex + 1, left, mid);
//         buildSegmentTree(2 * segIndex + 2, mid + 1, right);
//         segmentTree[segIndex] = segmentTree[2 * segIndex + 1] + segmentTree[2 * segIndex + 2];
//     }

//     void update(int segIndex, int left, int right) {
//         if (left == right) {
//             segmentTree[segIndex] = isPeak(left);
//               return;
//         }
//         int mid = (left + right) >> 1;
        
//             update(2 * segIndex + 1, left, mid);
//             update(2 * segIndex + 2, mid + 1, right);

//         segmentTree[segIndex] = segmentTree[2 * segIndex + 1] + segmentTree[2 * segIndex + 2];
//     }

//     void UpdatePoint(int value, int index, int segIndex, int left, int right){
//                nums[index] = value;
//               update(segIndex,left,right); 
//     }

//     int Query(int segIndex, int Qleft, int Qright, int left, int right) {
//         if (Qright < left || Qleft > right) return 0;
//         if (Qleft <= left && right <= Qright) return segmentTree[segIndex];
//         int mid = (left + right) >> 1;
//         int leftResult = Query(2 * segIndex + 1, Qleft, Qright, left, mid);
//         int rightResult = Query(2 * segIndex + 2, Qleft, Qright, mid + 1, right);
//         return leftResult + rightResult;
//     }

//     vector<int> countOfPeaks(vector<int>& num, vector<vector<int>>& queries) {
//         vector<int> ans;
//         int n = num.size();
//         segmentTree.resize(4 * n, 0);
//         nums = num;
//         buildSegmentTree(0, 0, n - 1);

//         for (auto& query : queries) {
//             if (query[0] == 1) {
//                 int result = Query(0, query[1] + 1, query[2] - 1, 0, n - 1);
//                 ans.push_back(result);
//             } else {
//                 UpdatePoint(query[2], query[1], 0, 0, n - 1);
//             }
//         }
//         return ans;
//     }
// };
















// // class Solution {
// // public:
    
// //     vector<int>segmentTree;
// //     vector<int>nums;
// //  int isPeak(int index) {
// //       if(index == 0 || index == nums.size()-1)
// //           return 0;
// //      return (nums[index] > nums[index-1] && nums[index] > nums[index+1]);     
// //  }
// //   void buildSegementTree(int segIndex, int left, int right){
// //        if(left == right){
// //            segmentTree[segIndex] = isPeak(left); 
// //        }
// //          int mid = (left + right)>>1;
// //          buildSegementTree(2*segIndex+1, left, mid);
// //          buildSegementTree(2*segIndex+2, mid,right);
// //        segmentTree[segIndex] = segmentTree[2*segIndex+1] + segmentTree[2*segIndex+2] ;  
// //   }
// //      void pointUpdate(int value, int index , int segindex, int left, int right) {
// //             if(left ==  right) {
// //                nums[index] = value; 
// //                segmentTree[segindex] = isPeak(index);
// //             }
// //            int mid = (left + right)>>1; 
// //             if(mid >= index) {
// //                pointUpdate(value, index,2*segindex+1,left,mid);
// //             }else{
// //                 pointUpdate(value, index,2*segindex+2,mid+1,right);
// //             }
// //           segmentTree[segindex] = segmentTree[2*segindex+1] + segmentTree[2*segindex+2];
// //      }
// //      int QueryP(int segIndex, int Qleft,int Qright,int left, int right){
// //                if(Qright < left  || Qleft > right ) {
// //                    return 0;
// //                }
// //               if(left <= Qleft && right <= Qright){
// //                   return segmentTree[segIndex];
// //               }
// //             int mid = (left + right )>>1;  
// //             int leftS = QueryP(2*segIndex+1,Qleft,Qright,left,mid);
// //             int rightS = QueryP(2*segIndex+2,Qleft,Qright,mid,right);
// //             return leftS + rightS;
// //      }
// //     vector<int> countOfPeaks(vector<int>& num, vector<vector<int>>& queries) {
// //      vector<int>ans;
// //        int n = num.size();
// //        segmentTree.resize(4*n,0);
// //        nums = num;
// //       for(auto query : queries) {
// //           if(query[0] == 1 ){ 
// //              int an = QueryP(0,query[1]+1,query[2]-1,0,n-1);
// //             ans.push_back(an);
// //           } else{
// //                pointUpdate(query[2],query[1],0,0,n-1);    
// //           }
// //       }
// //         return ans;
// //      }
// //  };

// // //     vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
// // //       vector<int>ans;
// // //       for(auto query : queries) {
// // //           if(query[0] == 1 ){
// // //              int an = 0;
// // //             for(int left = query[1] ; left <= query[2] ; left++) {
// // //                 if(left + 1 <= query[2] && left + 2 <= query[2] && nums[left] < nums[left+1]  && nums[left+1] > nums[left+2]) {
// // //                      an++;
// // //                   }
// // //              } 
// // //             ans.push_back(an);
// // //           } else{
// // //             nums[query[1]] = query[2];
// // //           }
// // //       }
// // //  return ans;
// // //     }
// // // };

// // /*
// // tc : O(Q*n) : 
// // sc : O(1);
// //  0 1 2 3 4 
// // [4,9,4,10,7]

// // [4,3,3,10,7]

// // [[2,3,2],[2,1,3],[1,2,3]]


// // */