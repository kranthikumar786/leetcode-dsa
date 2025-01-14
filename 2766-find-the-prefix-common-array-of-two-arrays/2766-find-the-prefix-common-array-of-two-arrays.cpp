class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
     unordered_map<int,int>MP;
     vector<int>ans(A.size(), 0);
    int n = A.size();
   for(int i = 0 ; i < n ; i++) {
        MP[A[i]]++;
        int count = 0;
      for(int j = 0 ; j <= i ;j++) {
            if(MP[B[j]]) {
                count++;
            }
      }
      ans[i] = count;
   }
  return ans;
  
    }
};
/*



[1,2,3] 
[1,2,3]

      while travesing meintane   frequncy of A elements :
      C[] =
       O(n*n) : 
       tc : O(n) :  
  */