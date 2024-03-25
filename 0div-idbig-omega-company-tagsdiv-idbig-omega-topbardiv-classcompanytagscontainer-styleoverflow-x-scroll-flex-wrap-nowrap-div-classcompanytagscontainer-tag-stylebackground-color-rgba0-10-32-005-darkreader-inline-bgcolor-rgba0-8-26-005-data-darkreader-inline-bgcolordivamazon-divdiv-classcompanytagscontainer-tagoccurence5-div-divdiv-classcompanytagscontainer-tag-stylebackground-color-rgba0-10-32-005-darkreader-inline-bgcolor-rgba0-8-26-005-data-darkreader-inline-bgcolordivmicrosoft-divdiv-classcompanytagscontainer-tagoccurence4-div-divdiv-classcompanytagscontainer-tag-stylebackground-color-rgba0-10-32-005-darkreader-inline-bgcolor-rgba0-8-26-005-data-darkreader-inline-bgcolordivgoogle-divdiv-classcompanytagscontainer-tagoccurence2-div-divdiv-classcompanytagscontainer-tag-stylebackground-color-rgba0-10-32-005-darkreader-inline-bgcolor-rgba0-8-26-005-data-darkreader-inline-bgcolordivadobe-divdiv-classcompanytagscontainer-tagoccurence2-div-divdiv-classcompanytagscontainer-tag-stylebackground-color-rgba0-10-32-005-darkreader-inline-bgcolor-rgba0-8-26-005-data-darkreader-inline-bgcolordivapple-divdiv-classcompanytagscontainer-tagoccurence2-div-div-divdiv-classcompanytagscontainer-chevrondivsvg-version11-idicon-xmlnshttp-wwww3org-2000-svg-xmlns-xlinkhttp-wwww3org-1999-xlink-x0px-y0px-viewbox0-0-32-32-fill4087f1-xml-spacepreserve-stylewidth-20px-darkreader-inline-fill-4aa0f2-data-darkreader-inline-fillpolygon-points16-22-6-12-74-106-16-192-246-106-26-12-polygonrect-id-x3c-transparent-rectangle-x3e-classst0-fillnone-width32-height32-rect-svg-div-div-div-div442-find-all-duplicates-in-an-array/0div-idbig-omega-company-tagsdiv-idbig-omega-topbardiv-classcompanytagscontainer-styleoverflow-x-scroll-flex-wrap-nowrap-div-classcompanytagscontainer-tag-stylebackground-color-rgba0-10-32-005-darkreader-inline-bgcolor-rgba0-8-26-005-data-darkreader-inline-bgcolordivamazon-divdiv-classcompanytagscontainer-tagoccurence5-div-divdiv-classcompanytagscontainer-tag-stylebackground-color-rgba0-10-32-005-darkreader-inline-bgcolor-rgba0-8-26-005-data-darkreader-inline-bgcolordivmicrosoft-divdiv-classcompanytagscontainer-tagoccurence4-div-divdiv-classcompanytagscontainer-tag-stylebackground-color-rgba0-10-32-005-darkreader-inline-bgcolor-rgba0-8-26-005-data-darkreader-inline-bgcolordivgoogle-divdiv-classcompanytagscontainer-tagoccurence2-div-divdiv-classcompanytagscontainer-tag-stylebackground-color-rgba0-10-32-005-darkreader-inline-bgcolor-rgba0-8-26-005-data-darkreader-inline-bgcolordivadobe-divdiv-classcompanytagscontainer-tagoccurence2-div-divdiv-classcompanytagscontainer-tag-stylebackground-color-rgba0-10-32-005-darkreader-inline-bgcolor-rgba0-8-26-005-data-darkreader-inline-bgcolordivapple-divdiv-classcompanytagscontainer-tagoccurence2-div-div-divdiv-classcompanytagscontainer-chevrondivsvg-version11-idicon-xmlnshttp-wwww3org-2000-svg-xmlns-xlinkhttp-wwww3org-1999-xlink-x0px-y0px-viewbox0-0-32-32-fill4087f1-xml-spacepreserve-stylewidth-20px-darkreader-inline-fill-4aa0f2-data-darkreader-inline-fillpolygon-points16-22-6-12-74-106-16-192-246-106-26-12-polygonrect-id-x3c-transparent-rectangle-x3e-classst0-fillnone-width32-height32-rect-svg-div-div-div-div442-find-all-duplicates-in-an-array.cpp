class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n+1 , 0);
       for(int i = 0 ; i < n ; i++){
           ans[nums[i]]++; 
       }
      vector<int>ansT;
      for(int i = 0 ; i <= n ; i++) {
             if(ans[i] == 2) {
                 ansT.push_back(i);
             }
      } 
     return ansT;   
    }
};