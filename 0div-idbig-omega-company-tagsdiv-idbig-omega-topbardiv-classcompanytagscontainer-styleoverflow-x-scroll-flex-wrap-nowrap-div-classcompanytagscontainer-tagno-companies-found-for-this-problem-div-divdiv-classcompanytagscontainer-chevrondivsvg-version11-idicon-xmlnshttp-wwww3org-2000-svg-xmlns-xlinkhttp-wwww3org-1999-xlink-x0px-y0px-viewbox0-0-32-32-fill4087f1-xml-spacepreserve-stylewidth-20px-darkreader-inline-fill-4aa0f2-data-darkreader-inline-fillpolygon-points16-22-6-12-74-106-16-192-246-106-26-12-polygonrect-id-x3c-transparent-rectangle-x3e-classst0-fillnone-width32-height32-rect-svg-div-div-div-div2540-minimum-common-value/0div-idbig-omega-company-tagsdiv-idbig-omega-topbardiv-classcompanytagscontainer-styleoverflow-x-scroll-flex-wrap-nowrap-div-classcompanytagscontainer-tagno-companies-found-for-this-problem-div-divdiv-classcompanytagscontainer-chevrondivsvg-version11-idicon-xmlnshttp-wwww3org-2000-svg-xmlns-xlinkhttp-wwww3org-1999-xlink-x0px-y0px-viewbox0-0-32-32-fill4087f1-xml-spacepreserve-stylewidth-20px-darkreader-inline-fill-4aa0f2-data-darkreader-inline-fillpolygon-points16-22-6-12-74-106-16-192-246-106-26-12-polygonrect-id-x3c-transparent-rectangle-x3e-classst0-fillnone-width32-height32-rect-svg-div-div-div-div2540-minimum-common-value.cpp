class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
     
     set<int>SetV;
        for(int  num : nums1) {
             SetV.insert(num);
        } 
        
       int minVal = INT_MAX ;
        for(int num : nums2) {
            if(SetV.find(num) != SetV.end()) {
                  minVal = min(minVal , num);
            }
        }
  return minVal == INT_MAX ? -1 : minVal;
    }
};