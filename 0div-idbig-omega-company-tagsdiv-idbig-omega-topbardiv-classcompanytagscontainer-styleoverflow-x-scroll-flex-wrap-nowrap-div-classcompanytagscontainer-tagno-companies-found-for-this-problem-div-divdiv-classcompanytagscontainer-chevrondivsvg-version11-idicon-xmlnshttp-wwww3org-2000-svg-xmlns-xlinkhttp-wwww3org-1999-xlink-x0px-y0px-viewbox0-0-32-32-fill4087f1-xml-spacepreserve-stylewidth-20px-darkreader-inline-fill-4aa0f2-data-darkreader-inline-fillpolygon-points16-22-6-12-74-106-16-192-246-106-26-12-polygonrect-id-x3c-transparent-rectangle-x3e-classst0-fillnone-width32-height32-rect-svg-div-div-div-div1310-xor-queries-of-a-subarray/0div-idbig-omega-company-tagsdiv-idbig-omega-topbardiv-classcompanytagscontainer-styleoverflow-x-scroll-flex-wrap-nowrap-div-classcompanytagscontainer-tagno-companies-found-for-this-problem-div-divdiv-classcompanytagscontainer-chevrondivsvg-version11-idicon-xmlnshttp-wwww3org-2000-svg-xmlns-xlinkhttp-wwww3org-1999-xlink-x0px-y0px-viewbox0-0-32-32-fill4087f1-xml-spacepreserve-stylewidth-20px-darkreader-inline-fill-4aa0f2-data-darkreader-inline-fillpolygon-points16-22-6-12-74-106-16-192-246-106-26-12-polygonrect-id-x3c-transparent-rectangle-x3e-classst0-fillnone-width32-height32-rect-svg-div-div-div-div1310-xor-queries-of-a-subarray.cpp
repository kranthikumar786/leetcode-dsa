class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int arrSize = arr.size();
        int queSize = queries.size();
         for(int i = 0 ; i < queSize ; i++) {
                int leftIndex = queries[i][0];
                int rightIndex = queries[i][1];
                int xorV = 0; 
              for( ; leftIndex <= rightIndex ; leftIndex++ ) {
                       xorV ^= arr[leftIndex];
              } 
              ans.push_back(xorV);
          }
       return ans; 
    }
};