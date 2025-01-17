class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
     int XOROfAll = 0 ;
  for(int num : derived){
      XOROfAll ^= num; 
  }
  return XOROfAll == 0 ;
    }
};