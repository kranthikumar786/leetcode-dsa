class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int left = 0, count = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == maxEle)
                count++;

            while (count >= k) {
                ans += (n - right); // all subarrays starting from left and ending from right to n-1 are valid
                if (nums[left] == maxEle)
                    count--;
                left++;
            }
        }
        return ans;
    }
};




// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int maxEle = *max_element(nums.begin(),nums.end());
//         unordered_map<int,int>um; 
//         int n = nums.size();
//         long long ans = 0;
//         int left = 0;
//         int right = 0;
//         for(int left = 0; left < n ; left++) {
//                while(right < n ) {
//                      if(maxEle == nums[right])
//                          um[maxEle]++;
//                       right++;  
//                      if(um[maxEle] >= k){
//                         ans++;
//                       }  
//               }

//            if(maxEle == nums[left])
//                 um[maxEle]--;
                     
//         if(um[maxEle] >= k){
//               ans++;
//             }
//         }
//        return ans;
//     }
// };