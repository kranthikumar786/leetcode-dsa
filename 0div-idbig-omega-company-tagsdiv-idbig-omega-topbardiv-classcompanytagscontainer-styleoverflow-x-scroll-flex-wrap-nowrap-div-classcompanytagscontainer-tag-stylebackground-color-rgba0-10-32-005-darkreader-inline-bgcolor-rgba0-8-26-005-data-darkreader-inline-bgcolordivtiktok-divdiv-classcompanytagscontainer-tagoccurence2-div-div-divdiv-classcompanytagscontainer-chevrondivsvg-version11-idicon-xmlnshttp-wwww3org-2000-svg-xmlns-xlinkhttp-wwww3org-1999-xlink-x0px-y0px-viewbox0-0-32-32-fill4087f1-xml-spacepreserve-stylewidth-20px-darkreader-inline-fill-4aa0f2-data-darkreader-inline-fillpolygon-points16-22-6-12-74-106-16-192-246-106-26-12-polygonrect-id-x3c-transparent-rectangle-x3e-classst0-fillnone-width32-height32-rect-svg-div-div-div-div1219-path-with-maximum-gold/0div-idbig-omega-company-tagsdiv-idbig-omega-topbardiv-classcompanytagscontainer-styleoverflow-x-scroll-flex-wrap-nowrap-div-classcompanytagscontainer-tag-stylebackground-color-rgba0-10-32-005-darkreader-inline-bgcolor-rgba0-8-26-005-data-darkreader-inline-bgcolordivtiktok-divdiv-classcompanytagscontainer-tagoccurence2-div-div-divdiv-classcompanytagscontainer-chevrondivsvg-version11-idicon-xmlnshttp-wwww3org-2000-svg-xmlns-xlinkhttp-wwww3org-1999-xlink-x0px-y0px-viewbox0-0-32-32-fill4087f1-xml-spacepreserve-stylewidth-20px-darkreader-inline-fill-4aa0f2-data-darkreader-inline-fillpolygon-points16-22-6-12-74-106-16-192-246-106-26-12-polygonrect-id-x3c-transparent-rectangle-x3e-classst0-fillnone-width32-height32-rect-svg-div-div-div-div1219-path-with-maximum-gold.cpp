class Solution {
    int n,m;
    vector<vector<int>> g;
    int getGold(int i,int j,vector<vector<int>>& visited){
        if(i >= n || i < 0 || j < 0 || j >= m) return 0;
        if(visited[i][j]) return 0;
        if(g[i][j] == 0) return 0;
        
        visited[i][j]=1;
        int l = getGold(i,j-1,visited);
        int r = getGold(i,j+1,visited);
        int u = getGold(i-1,j,visited);
        int d = getGold(i+1,j,visited);
        visited[i][j]=0;

        return g[i][j]+max({l,r,u,d});
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        n=grid.size();
        m=grid[0].size();
        g=grid;
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    vector<vector<int>> visited(n,vector<int>(m,0));
                    // set<pair<int,int>> visited;
                    int gold = getGold(i,j,visited);
                    res = max(gold,res);
                }
            }
        }
        return res;
    }
};