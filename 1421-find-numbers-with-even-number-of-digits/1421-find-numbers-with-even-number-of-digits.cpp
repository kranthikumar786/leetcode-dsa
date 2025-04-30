class SegmentTree {
    vector<int> tree;
    int n;

    int isEvenDigit(int num) {
        int count = 0;
        while (num) {
            count++;
            num /= 10;
        }
        return count % 2 == 0;
    }

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = isEvenDigit(nums[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    int queryTotalEvenCount() const {
        return tree[0];
    }
};

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        SegmentTree tree(nums);
        return tree.queryTotalEvenCount();
    }
};



// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//      int ans = 0; 
//      for(int num :nums) {
//            int digits = 0;
//            while (num) {
//              digits++ ;
//              num/=10; 
//            }
//             if(digits%2 == 0){
//                 ans++;
//             }
//      }
//      return ans;
//     }
// };