class Solution {
public:
    bool divideArray(vector<int>& nums) {
    bitset<501> parity=0;
     for(int num : nums){
        parity.flip(num);
     } 
     return parity.count() ? 0 : 1;
    //    unordered_map<int,int>UM;
    //    for(int num : nums){
    //        UM[num]++;
    //    }
    //   for(auto itr = UM.begin() ; itr != UM.end() ; itr++){
    //         if(((itr->second)%2) == 1){
    //              return false;
    //         }
    //   } 
    //   return true;
    }
};