class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int n = nums.size();
        vector<int>ans;
     unordered_map<int,int>UM;
        
     for(int i = 0 ; i < n ; i++) {
          UM[nums[i]]++;
     }   
      
     for(auto i = UM.begin(); i != UM.end() ; i++) {
           if(i->second == 1) {
               ans.push_back(i->first);
           }
     }
        return ans;
    }
};