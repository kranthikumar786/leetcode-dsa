class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
     
     int singleDigits = 0 , doubleDigits = 0 ;
      
        for(int i = 0 ; i < nums.size() ; i++) {
                if(nums[i] < 10) {
                    singleDigits += nums[i];
                } else {
                    doubleDigits+= nums[i];
                }
        }
         return (singleDigits != doubleDigits);        
    }
};