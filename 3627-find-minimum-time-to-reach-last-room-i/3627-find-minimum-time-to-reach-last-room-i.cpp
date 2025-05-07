class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int totalRows = moveTime.size();
        int totalColumns = moveTime[0].size();

        vector<vector<int>> DP(totalRows, vector<int>(totalColumns, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> minHeap;

        minHeap.push({0, {0, 0}});
        DP[0][0] = 0;

        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        while (!minHeap.empty()) {
            auto currentRoom = minHeap.top();
            minHeap.pop();

            int currentTime = currentRoom.first;
            int curRow = currentRoom.second.first;
            int curCol = currentRoom.second.second;

            if (currentTime > DP[curRow][curCol]) continue;

            if (curRow == totalRows - 1 && curCol == totalColumns - 1) {
                return currentTime;
            }

            for (auto& dire : directions) {
                int newRow = curRow + dire[0];
                int newCol = curCol + dire[1];

                if (newRow >= 0 && newRow < totalRows && newCol >= 0 && newCol < totalColumns) {
                    int nextTime = max(moveTime[newRow][newCol], currentTime) + 1;

                    if (nextTime < DP[newRow][newCol]) {
                        DP[newRow][newCol] = nextTime;
                        minHeap.push({nextTime, {newRow, newCol}});
                    }
                }
            }
        }

        return -1;
    }
};
