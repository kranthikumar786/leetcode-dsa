class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

    long long ans = 0;
    int n = nums.size();
       if(n < 3 ) {return 0;}
       vector<int>maxValueTill(n,-1);
         maxValueTill[n-1] = nums[n-1];
      for(int k = n -2; k >= 2 ; k--) {
             maxValueTill[k] = max(maxValueTill[k+1], nums[k]);                 
        }
    for(int i = 0 ;i < n-2 ; i++) {
          for(int j = i +1; j < n-1  ;j++ ) {
                long long aa = (long long)(nums[i]-nums[j])*(maxValueTill[j+1]);
                  ans = max(ans,aa);
               }
          } 
     return ans <= 0 ? 0 : ans;  
    }
};