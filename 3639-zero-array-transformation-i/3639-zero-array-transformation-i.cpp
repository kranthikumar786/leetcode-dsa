class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (auto query : queries) {
            int left = query[0];
            int right = query[1];
            diff[left] += 1;
            if (right + 1 < n) diff[right + 1] -= 1;
        }

        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (diff[i] < nums[i]) {
                return false;
            }
        }

        return true;
    }
};


// class Solution {
// public:
//     bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//      int  n = nums.size();
//      vector<int>diff(n+1,0);
//            diff[0] = nums[0];
//        for(int i = 1; i < n; i++) {
//             diff[i] = nums[i] - nums[i-1];
//             //cout<<diff[i]<<"::";
//        }  
//        for(auto query : queries) {
//                int left = query[0];
//                int right = query[1];
//               diff[left] += 1;
//               diff[right+1] -=1 ; 
//        } 
//        for(int i = 1 ; i <= n ;i++) {
//             diff[i] = diff[i] + diff[i-1];
//             cout<<diff[i]<<":";
//        } 
//         for(int i = 0 ;i < n ;i++) {
//           if(diff[i] < nums[i]){return false;}
//         }
//  return true;
//     }
// };