class Solution {
    int[] subtreeXor, inTime, outTime;
    int timer = 0;

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for(int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }

        subtreeXor = new int[n];
        inTime = new int[n];
        outTime = new int[n];

        dfs(0, -1, nums, graph);

        int totalXor = subtreeXor[0];
        int minScore = Integer.MAX_VALUE;

        for(int[] edge1 : edges) {
            int u1 = edge1[0], v1 = edge1[1];
            int child1 = inTime[u1] > inTime[v1] ? u1 : v1;

            for(int[] edge2 : edges) {
                if(edge1 == edge2) continue;

                int u2 = edge2[0], v2 = edge2[1];
                int child2 = inTime[u2] > inTime[v2] ? u2 : v2;

                int x1 = subtreeXor[child1], x2 = subtreeXor[child2];

                int x3;
                if (isAncestor(child1, child2)) {
                    x2 = subtreeXor[child2];
                    x1 = subtreeXor[child1] ^ subtreeXor[child2];
                    x3 = totalXor ^ subtreeXor[child1];
                } else if (isAncestor(child2, child1)) {
                    x1 = subtreeXor[child1];
                    x2 = subtreeXor[child2] ^ subtreeXor[child1];
                    x3 = totalXor ^ subtreeXor[child2];
                } else {
                    x1 = subtreeXor[child1];
                    x2 = subtreeXor[child2];
                    x3 = totalXor ^ x1 ^ x2;
                }

                int max = Math.max(x1, Math.max(x2, x3));
                int min = Math.min(x1, Math.min(x2, x3));
                minScore = Math.min(minScore, max - min);
            }
        }

        return minScore;
    }

    void dfs(int node, int parent, int[] nums, List<List<Integer>> graph) {
        inTime[node] = ++timer;
        subtreeXor[node] = nums[node];
        for(int nei : graph.get(node)) {
            if(nei != parent) {
                dfs(nei, node, nums, graph);
                subtreeXor[node] ^= subtreeXor[nei];
            }
        }
        outTime[node] = ++timer;
    }

    boolean isAncestor(int u, int v) {
        return inTime[u] <= inTime[v] && outTime[u] >= outTime[v];
    }
}
