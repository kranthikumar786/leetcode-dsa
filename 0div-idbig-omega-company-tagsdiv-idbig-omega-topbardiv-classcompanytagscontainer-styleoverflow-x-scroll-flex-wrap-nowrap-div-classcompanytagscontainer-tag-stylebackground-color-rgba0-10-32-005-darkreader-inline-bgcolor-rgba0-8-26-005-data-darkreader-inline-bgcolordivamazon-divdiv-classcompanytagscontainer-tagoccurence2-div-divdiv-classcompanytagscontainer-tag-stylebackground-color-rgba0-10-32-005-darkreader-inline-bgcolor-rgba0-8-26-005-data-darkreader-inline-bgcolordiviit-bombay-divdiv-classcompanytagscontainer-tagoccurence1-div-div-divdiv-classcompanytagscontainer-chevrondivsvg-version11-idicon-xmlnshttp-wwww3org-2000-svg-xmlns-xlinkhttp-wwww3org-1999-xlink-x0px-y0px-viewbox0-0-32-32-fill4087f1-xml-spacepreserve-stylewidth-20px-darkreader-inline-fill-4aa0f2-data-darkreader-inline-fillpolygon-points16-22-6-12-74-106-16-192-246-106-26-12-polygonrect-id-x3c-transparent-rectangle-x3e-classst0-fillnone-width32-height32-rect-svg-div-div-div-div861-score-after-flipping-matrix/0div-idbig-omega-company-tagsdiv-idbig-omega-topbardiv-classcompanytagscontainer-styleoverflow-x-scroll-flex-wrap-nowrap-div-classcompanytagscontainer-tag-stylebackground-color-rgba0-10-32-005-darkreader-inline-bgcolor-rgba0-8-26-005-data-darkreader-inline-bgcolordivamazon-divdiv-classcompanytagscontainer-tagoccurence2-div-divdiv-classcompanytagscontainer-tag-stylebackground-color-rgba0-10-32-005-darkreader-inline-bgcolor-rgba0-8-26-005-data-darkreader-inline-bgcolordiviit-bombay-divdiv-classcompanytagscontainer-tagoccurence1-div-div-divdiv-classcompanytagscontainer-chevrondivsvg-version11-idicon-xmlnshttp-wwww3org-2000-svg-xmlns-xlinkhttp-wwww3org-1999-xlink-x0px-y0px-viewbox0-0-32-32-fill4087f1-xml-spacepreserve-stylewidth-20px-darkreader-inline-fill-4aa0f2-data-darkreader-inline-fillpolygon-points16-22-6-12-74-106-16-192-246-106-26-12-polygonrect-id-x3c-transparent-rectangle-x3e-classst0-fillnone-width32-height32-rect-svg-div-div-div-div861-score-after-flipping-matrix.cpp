class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<n;j++)
                {
                    grid[i][j] = 1- grid[i][j];
                }
            }
        }
        
        for(int i=1;i<n;i++)
        {
            int one_c = 0;
            for(int j=0;j<m;j++)
            {
                one_c+=grid[j][i];
            }
            
            int zero_c = m - one_c;
            
            if(one_c < zero_c)
            {
                for(int j=0;j<m;j++)
                {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }
        
        int sum = 0;
        for(int i=0;i<m;i++)
        {
            int num = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][n-1-j])num = num | grid[i][n-1-j]<<j;
            }
            sum+=num;
        }
        
        return sum;
    }
};