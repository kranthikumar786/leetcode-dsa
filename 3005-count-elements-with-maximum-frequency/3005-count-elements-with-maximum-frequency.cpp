class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>Frequency;
        for(int num : nums){
            Frequency[num]++;
              }
         int maxFrequncy = 0 ;
       for(auto[num,frequency] : Frequency) {
            maxFrequncy = max(maxFrequncy,frequency);
          }
       int totalFre = 0; 
     for(auto[num,frequency] : Frequency) {
         if(frequency == maxFrequncy) {
                 totalFre += maxFrequncy;
          }
        }   
        return totalFre;
    }
};

/*
[1,2,3,4,5] = >Pass
[1,1,1,1,1]  = > pass
[1,2,2,3,1,4] = > pass
[5,4,3,2,1]  = > pass.
[1] = >pass
[100] = >pass

*/