class Solution {
public:
    int singleNumber(vector<int>& nums) {

     unordered_map<int,int>fre;
     for(int num : nums){
           fre[num]++;
     }  
    for(auto i = fre.begin() ; i != fre.end() ; i++) {
            if( i->second  == 1) {
                   return i->first;
            }
    } 
  return 0;
    }
};