class Solution {
public:
    int countLargestGroup(int n) {
         unordered_map<int,int>um;
            int maxLength =  1;
     for(int i = 1; i <= n ; i++) {
          if(i < 10){
            um[i]++;
          } else{
              int  num = i;
               int sum = 0 ;
               while(num){
                     sum += (num%10);
                       num/=10;   
               }
              um[sum]++;
              maxLength = max(maxLength,um[sum]); 
          }
     }
     int ans = 0 ;
     for(auto itr : um){
          if(itr.second == maxLength ) {
              ans++;
          }
     }
     return ans;
    }
};