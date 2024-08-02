class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        
        int window = accumulate(nums.begin(),nums.end(),0);
        
        int minL = INT_MAX;
        
        int oneCount = 0;
        for(int i=0;i<window;i++)oneCount+=nums[i];
        
        minL = min(minL,window-oneCount);
        
        int right = window;
        int left = 0;
        
        while(left<n)
        {
            oneCount-=nums[left++];
            oneCount+=nums[right%n]; 
            minL = min(minL,window-oneCount);
            right++;
        }
                
        return minL;
    }
};