class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        
        pq.push({0, 0, 0, 0});  
        minTime[0][0] = 0;
        
        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        while (!pq.empty()) {
            auto [t, move, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == m - 1)
                return t;

            if (t > minTime[r][c]) continue;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int waitTime = max(t, moveTime[nr][nc]);
                    int moveCost = (move % 2 == 0) ? 1 : 2;
                    int newTime = waitTime + moveCost;

                    if (newTime < minTime[nr][nc]) {
                        minTime[nr][nc] = newTime;
                        pq.push({newTime, move + 1, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
