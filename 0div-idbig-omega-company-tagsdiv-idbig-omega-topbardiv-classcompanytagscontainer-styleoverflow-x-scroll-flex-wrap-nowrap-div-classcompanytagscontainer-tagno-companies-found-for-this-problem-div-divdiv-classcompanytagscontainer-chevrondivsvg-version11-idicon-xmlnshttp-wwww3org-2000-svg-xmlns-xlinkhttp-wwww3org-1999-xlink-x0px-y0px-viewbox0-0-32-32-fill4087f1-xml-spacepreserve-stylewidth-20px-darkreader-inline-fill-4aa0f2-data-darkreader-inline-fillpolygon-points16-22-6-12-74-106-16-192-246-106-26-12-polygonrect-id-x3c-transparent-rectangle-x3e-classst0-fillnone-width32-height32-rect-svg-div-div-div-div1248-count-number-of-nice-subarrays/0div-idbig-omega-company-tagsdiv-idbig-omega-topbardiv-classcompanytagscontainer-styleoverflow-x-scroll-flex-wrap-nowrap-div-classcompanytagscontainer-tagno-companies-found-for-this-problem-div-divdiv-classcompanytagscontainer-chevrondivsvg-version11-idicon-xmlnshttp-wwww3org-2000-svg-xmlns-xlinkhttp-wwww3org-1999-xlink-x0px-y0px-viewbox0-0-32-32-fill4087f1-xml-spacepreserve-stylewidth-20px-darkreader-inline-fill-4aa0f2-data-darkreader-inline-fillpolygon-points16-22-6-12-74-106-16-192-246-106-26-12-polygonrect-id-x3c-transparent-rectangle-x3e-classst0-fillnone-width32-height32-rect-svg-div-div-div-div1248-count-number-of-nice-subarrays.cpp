class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int subarrays = 0,n = nums.size() , curSum = 0;;
        /*for(int i = 0 ; i < n ;i++) {
              int cnt = 0;
             for(int j = i ; j < n ;j++) {
                   if(nums[j]%2) {
                         cnt++;
                   }
                   if(cnt == k) {
                        ans++;
                   }
             }
        }
        */
        
       unordered_map<int,int>prefixSum ;
        prefixSum[curSum]  =1;
        for(int i = 0 ; i < n ;i++) {
            curSum += nums[i]%2;
            if(prefixSum.find(curSum - k)!= prefixSum.end()) {
                subarrays = subarrays + prefixSum[curSum- k];
            }
            prefixSum[curSum]++;
        }
        
        return subarrays;
    }
};