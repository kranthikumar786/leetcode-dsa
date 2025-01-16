class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       vector<int>nums3;
       int  n1 = nums1.size() , n2 = nums2.size();
       int ans = 0,xor1 = 0 ,xor2 =0;
       for(int num : nums1){
         xor1 ^= num;
       }
       for(int num : nums2){
         xor2 ^= num;
       }
      if(n1&1){
        ans ^= xor2;
      } 
      if(n2&1){
        ans ^= xor1;
      }
      return ans;
    }
};

/*


for(int i = 0 ; i < n1 ; i++) {
           int xor1 = 0;
          for(int j = 0; j < n2 ;j++) {
              xor1 ^= (nums1[i] ^ nums2[j]); 
          }
         ans ^= xor1;
        //  nums3.push_back(xor1);
       }
    //     int ans = 0;
    //    for(int i = 0 ; i < nums3.size() ; i++) {
    //     ans^= nums3[i];
    //    }
ex 2: 

 01 : 
 11 
 ---
010 - >2 
100 -
----
110 : 6 : 

------------------------------

10
11
--
01 - 1
10 - 
---
10
10 - > 0 :



 Optimization ideas : 
  
  can't directly do prefix sum stuff , since here 0^1 at current movment and later moment is differnt 
   where as 1 + 1 now  & later  leads to same results 
---------------------------------------
 tc : O(n*n) : 10^5 *10^5 = 10^10 , can expecte TLE :
 sc: o(1) :
*/