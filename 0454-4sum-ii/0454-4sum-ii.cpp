class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
     int ans = 0;
      unordered_map<int,int>num_4;
       for(int num : nums3) {
            for(int num_2 : nums4) {
            num_4[num + num_2]++;
            }
       }
       for(int num_1 : nums1) {
             for(int num_2 : nums2) {
                int sum = num_1 + num_2;
                 if(num_4[-(sum)] >= 1){
                  ans += num_4[-(sum)];
                }
               }
            }
 return ans;
    }
};