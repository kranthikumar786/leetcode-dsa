class RangeFreqQuery {
    struct Node {
        unordered_map<int, int> freq;
    };

    vector<Node> seg;
    int n;

private:
    void merge(int ind) {
        for (const auto& entry : seg[2 * ind + 1].freq) {
            seg[ind].freq[entry.first] += entry.second;
        }
        for (const auto& entry : seg[2 * ind + 2].freq) {
            seg[ind].freq[entry.first] += entry.second;
        }
    }

    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind].freq[arr[low]] = 1;
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        merge(ind);
    }
    int rangeF(int ind, int low, int high, int l, int r, int val) {
        if (r < low || high < l) { // non-overlapping
            return 0;
        }
        if (l <= low && high <= r) { // complete overlap
            return seg[ind].freq[val];
        }
        // partial overlap
        int mid = (low + high) / 2;
        int left = rangeF(2 * ind + 1, low, mid, l, r, val);
        int right = rangeF(2 * ind + 2, mid + 1, high, l, r, val);
        return left + right;
    }

public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        seg.resize(4*n+1);
        build(0, 0, n - 1, arr);
    }

    int query(int left, int right, int value) {
        return rangeF(0, 0, n - 1, left, right, value);
    }
};



// class RangeFreqQuery {
// public:
//   int n ;
//    vector<int>nums;
//     RangeFreqQuery(vector<int>& arr) {
//         nums = arr;
//         int n = arr.size();
//     }
//     int query(int left, int right, int value) {
//          int cnt = 0 ; 
//            while(left <= right){
//                if(nums[left] == value){
//                     cnt++;
//                }
//                left++;
//            }
//      return cnt;
//     }
// };

// /*
// TLE
// */
// /**
//  * Your RangeFreqQuery object will be instantiated and called as such:
//  * RangeFreqQuery* obj = new RangeFreqQuery(arr);
//  * int param_1 = obj->query(left,right,value);
//  */