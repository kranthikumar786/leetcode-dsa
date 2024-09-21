class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> col(m), row(n);
        
        for(int r = 0; r < m; r++)
            for(int c = 0; c < n; c++)
                if(!matrix[r][c]) col[c] = row[r] = true;
        
        for(int r = 0; r < m; r++)
            for(int c = 0; c < n; c++)
                matrix[r][c] = col[c] || row[r] ? 0 : matrix[r][c];
    }
};