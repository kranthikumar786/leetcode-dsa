class NumArray {
public:
    int n;
    vector<int> segmentTree;

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4 * n, 0);
        buildSegmentTree(0, 0, n - 1, nums);
    }

    void buildSegmentTree(int index, int left, int right, vector<int>& nums) {
        if (left == right) {
            segmentTree[index] = nums[left];
            return;
        }
        int mid = (left + right) >> 1;
        buildSegmentTree(2 * index + 1, left, mid, nums);
        buildSegmentTree(2 * index + 2, mid + 1, right, nums);
        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
    }

    void updateValue(int sindex, int left, int right, int index, int val) {
        if (left == right) {
            segmentTree[index] = val;
            return;
        }
        int mid = (left + right) >> 1;
        if (sindex <= mid)
            updateValue(sindex, left, mid, 2 * index + 1, val);
        else
            updateValue(sindex, mid + 1, right, 2 * index + 2, val);
        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
    }

    int Query(int sindex, int left, int right, int Qleft, int Qright) {
        if (Qright < left || right < Qleft)
            return 0;
        if (Qleft <= left && right <= Qright)
            return segmentTree[sindex];
        int mid = (left + right) >> 1;
        int leftSum = Query(2 * sindex + 1, left, mid, Qleft, Qright);
        int rightSum = Query(2 * sindex + 2, mid + 1, right, Qleft, Qright);
        return leftSum + rightSum;
    }

    void update(int index, int val) {
        updateValue(index, 0, n - 1, 0, val);
    }

    int sumRange(int left, int right) {
        return Query(0, 0, n - 1, left, right);
    }
};


// class NumArray {
// public:
//     int n ;
//     vector<int>segmentTree;
//     NumArray(vector<int>& nums) {
//         n = nums.size();
//         segmentTree.resize(4*n,0);
//         buildsegemntTree(0,0,n-1,nums);  
//     }
//     void buildsegemntTree(int index, int left, int right, vector<int>&nums){
//           if(left == right){
//               segmentTree[index] = nums[left];
//                return;
//           }
//           int mid = (left + right )>>1;
//           buildsegemntTree(2*index+1, left,mid,nums);
//           buildsegemntTree(2*index+2, mid+1,right,nums);
//       segmentTree[index] = segmentTree[2*index+1]  + segmentTree[2*index+2] ;
//     }
//     void updateValue(int sindex, int left, int right,int index,int val) {
//           if(left == right){
//             segmentTree[index] = val;
//              return;
//           }
//          int mid = (left + right)>>1;
//         if(mid <= sindex) {
//             updateValue(sindex,left, mid,index,val);
//         }else{
//             updateValue(sindex,mid+1,right,index,val);
//         }
//        segmentTree[sindex] = segmentTree[2*sindex+1]  + segmentTree[2*sindex+2] ;
//     }

//    int Query(int sindex, int left, int right, int Qleft, int Qright){
//            if(Qright < left ||Qleft > right){
//             return 0;}
//           if(left <= Qleft && Qright <= right){
//               return segmentTree[sindex];
//           }
//            int mid = (left + right) >>1;
//           int leftS = Query(2*sindex+1,left, mid,Qleft, Qright);
//           int rightS = Query(2*sindex+2,mid+1,right,Qleft, Qright);
//          return leftS + rightS;
//    }
//     void update(int index, int val) {
//         updateValue(0,0,n-1,index,val);
//     }
//     int sumRange(int left, int right) {
//         return Query(0,0,n-1,left, right);
//     }
// };

// /**
//  * Your NumArray object will be instantiated and called as such:
//  * NumArray* obj = new NumArray(nums);
//  * obj->update(index,val);
//  * int param_2 = obj->sumRange(left,right);
//  */