class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    int bfsSizeGetter(vector<vector<int>>& grid, int row, int col) {
        if (grid[row][col] != -3) return 0;
        queue<pair<int, int>> holder;
        holder.push({row, col});
        grid[row][col] = -1;
        int size = 0;
        while (!holder.empty()) {
            auto [x, y] = holder.front();
            holder.pop();
            size++;
            for (int index = 0; index < 4; index++) {
                int newX = x + dx[index];
                int newY = y + dy[index];
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == -3) {
                    grid[newX][newY] = -1;
                    holder.push({newX, newY});
                }
            }
        }
        return size;
    }
    
    void bfsMarker(vector<vector<int>>& grid, int row, int col, int size) {
        queue<pair<int, int>> holder;
        holder.push({row, col});
        grid[row][col] = -2;
        set<pair<int, int>> markedWater;
        while (!holder.empty()) {
            auto [x, y] = holder.front();
            holder.pop();
            for (int index = 0; index < 4; index++) {
                int newX = x + dx[index];
                int newY = y + dy[index];
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()) {
                    if (grid[newX][newY] == -1) {
                        grid[newX][newY] = -2;
                        holder.push({newX, newY});
                    } else if (grid[newX][newY] >= 0 && markedWater.find({newX, newY}) == markedWater.end()) {
                        grid[newX][newY] += size;
                        markedWater.insert({newX, newY});
                    }
                }
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for(int row = 0 ; row < grid.size() ; row++)
            for(int col = 0 ; col < grid[0].size() ; col++)
                if(grid[row][col] == 1)
                    grid[row][col] = -3;
        
        for(int row = 0 ; row < grid.size() ; row++)
            for(int col = 0 ; col < grid[0].size() ; col++) {
                if(grid[row][col] == -3) {
                    int size = bfsSizeGetter(grid, row, col);
                    bfsMarker(grid, row, col, size);
                    maxSize = max(maxSize, size);
                }
            }
        
        int maxReturn = 0;
        for(int row = 0 ; row < grid.size() ; row++)
            for(int col = 0 ; col < grid[0].size() ; col++)
                maxReturn = max(maxReturn, grid[row][col]);
        
        return max(maxReturn + 1, maxSize);
    }
};