class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> count(n * n + 1, 0);  // Use correct variable name
        int missing = -1, duplicate = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (count[grid[i][j]] > 0) {
                    duplicate = grid[i][j];  // Found duplicate
                }
                count[grid[i][j]]++; 
            }
        } 
        
        for (int i = 1; i <= n * n; i++) {  // Start from 1
            if (count[i] == 0) {
                missing = i;
                break;
            }
        }

        return {duplicate, missing};  // ✅ Return inside the function
    }
};
