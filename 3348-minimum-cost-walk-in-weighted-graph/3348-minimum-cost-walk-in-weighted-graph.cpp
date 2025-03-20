class Solution {
public:
    vector<int> parent;
    vector<int> depth;

    int find(int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    void Union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 == root2) return;

        if (depth[root1] < depth[root2]) {
            swap(root1, root2);
        }

        parent[root2] = root1;
        if (depth[root1] == depth[root2])
            depth[root1]++;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        depth.resize(n, 0);
        vector<unsigned int> ComponenetCost(n, -1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto &edge : edges) {
            Union(edge[0], edge[1]);
        }

        for (auto &edge : edges) {
            int root = find(edge[0]);
            ComponenetCost[root] &= edge[2];
        }

        vector<int> answer;
        for (auto &que : query) {
            int start = que[0];
            int end = que[1];

            if (find(start) != find(end)) {
                answer.push_back(-1);
            } else {
                int root = find(start);
                answer.push_back(ComponenetCost[root]);
            }
        }

        return answer;
    }
};
