class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        for (int index = 0; index < n; index++) {
            while (sum + differenceArray[index] < nums[index]) {
                k++;
                if (k > queries.size()) {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1], val = queries[k - 1][2];

                if (right >= index) {
                    differenceArray[max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            sum += differenceArray[index];
        }
        return k;
    }
};


// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//        int k  = 0; 
//        int n = nums.size();
//        bool f = 0;
//      for(int i = 0 ; i < n ;i++) {
//              if(nums[i]!= 0){
//                  f = 1;
//                 break;
//              }
//          }
//      if(!f) return 0; 
//      int querySize = queries.size();
//       for(int q = 0 ; q < querySize ; q++){
//           int left = queries[q][0];
//           int right = queries[q][1];
//           int value = queries[q][2];
//           for(; left <= right ; left++){
//             nums[left] = (nums[left] <= value ? 0 : nums[left] - value);
//          }
//          bool f = 0;
//          for(int i = 0 ; i < n ;i++) {
//              if(nums[i]!= 0){
//                  f = 1;
//                 break;
//              }
//          }
//          k++;
//          if(!f) return k;
        
//      } 
//     return -1;
//       }
// };




/*

  [0,1,2] : 
   1 1 1 :
   1 1 1 : 
     3
   2 5 2 : 
    

  prefixSum won't help here ..
  
  2 2 4  :
  1 1 3 : 
  0 0 2 : 
  
  Not getting : 

    [2,0,3], queries = [[0,2,3],[0,2,1],[1,1,3]]
    [0,0,0] : 


      //  if(nums[left] == 0){
            //     continue;
            //  }
     */
