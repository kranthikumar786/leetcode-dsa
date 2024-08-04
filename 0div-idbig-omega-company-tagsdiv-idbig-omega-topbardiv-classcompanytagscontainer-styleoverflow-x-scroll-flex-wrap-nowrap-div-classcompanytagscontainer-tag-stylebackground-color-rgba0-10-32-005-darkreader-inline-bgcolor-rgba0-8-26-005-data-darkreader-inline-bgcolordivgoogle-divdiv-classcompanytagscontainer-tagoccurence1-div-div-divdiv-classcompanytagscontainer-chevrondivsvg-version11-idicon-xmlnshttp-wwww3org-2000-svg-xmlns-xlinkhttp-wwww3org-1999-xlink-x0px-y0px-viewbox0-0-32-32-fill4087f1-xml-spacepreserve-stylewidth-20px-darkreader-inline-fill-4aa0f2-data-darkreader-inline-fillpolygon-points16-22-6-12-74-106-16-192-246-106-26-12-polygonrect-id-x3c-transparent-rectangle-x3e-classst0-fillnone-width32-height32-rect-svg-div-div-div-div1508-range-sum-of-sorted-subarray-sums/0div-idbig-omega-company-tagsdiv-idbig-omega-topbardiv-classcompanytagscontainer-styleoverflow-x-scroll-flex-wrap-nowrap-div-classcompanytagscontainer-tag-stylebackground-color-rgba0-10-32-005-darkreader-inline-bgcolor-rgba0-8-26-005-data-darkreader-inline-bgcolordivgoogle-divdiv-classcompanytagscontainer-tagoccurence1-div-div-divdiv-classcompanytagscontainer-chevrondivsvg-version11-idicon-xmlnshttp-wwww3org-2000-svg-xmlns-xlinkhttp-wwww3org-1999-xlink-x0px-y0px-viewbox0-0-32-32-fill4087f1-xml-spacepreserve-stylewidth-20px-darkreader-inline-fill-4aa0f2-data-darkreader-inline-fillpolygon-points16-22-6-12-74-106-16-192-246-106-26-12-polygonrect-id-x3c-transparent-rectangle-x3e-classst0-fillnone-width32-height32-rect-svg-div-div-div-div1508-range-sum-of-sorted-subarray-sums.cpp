class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subarray;
               for(int j = 0 ; j < n ;j++) { 
                     int sum = 0;
                    for(int k = j ; k < n ;k++) {
                         sum += nums[k];
                        //cout<<sum<<" ";
                       subarray.push_back(sum); 
                    }
               }
          sort(subarray.begin(),subarray.end());
        int sum = 0 , Mod =1e9+7;
        for(int i = left-1 ; i <= right-1 ; i++) {
            sum = ((long)sum + subarray[i]) %Mod;
        }
        return sum; 
        
    }
};