class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
     int n = nums.size();
      int ans = 0;
    unordered_set<int>s;
    for(int num : nums){
         s.insert(num);
    }
    int distint = s.size();
      s.clear();
      for(int i = 0 ; i < n ;i++) {
              s.clear();
          for(int j = i ; j < n ;j++) {
                s.insert(nums[j]);
               if(s.size() == distint ) {
                  //ans++;
                  ans += (n-j);
                   break;
               }
          }
      }
         return ans;
    }
};

/*
[1,3,1,2,2,6]
[1,3,1,2,2,6]



*/