class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans = 0 ;
        vector<int>Hash(101,0);
        for(auto Values : nums){
            int left = Values[0];
            int right = Values[1];
           for(int i = left ; i <= right ; i++){
               Hash[i]++;
           }
        }
        for(int i = 1 ; i <= 100 ; i++){
               if(Hash[i] != 0){
                   ans++;
               }
        }
        return ans;
    }
};