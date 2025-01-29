class Solution {
public:
    bool dfs(int parent, const vector<vector<int>>& adjList, int src, vector<int>& visited) {
        visited[src] = 1;
        for (int neighbor : adjList[src]) {
            if (!visited[neighbor]) {
                if (dfs(src, adjList, neighbor, visited))
                    return true;
            } else if (neighbor != parent) {
                return true; 
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n + 1); 
        vector<int> removedEdge;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            vector<int> visited(n + 1, 0);
            if (dfs(-1, adjList, u, visited)) {
                removedEdge = {u, v};
                break;
            }
        }
        return removedEdge;
    }
};
