class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

     
        for(const auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;
        vector<unordered_set<int>> pre(numCourses);

        for(int u = 0; u < numCourses; ++u)
            if(!indegree[u])
                q.push(u);

        while(!q.empty()) {
            int u = q.front(); q.pop();

            for(int v : graph[u]) {
                pre[v].insert(u);
                pre[v].insert(pre[u].begin(), pre[u].end());

                indegree[v]--;
                if(!indegree[v])
                    q.push(v);
            }
        }

        
        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            ans[i] = pre[v].find(u) != pre[v].end();
        }

        return ans;
    }
};