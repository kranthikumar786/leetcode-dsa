class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>UM;
        for(int i : nums1) {
            UM[i]++;
        }
        
        for(int i = 0 ; i < nums2.size() ; i++) {
              if(UM.find(nums2[i]) != UM.end()) {
                  ans.push_back(nums2[i]);
                  UM[nums2[i]]--;
                  if(UM[nums2[i]] == 0) {UM.erase(nums2[i]);}
              }
        }
        return ans;
    }
};