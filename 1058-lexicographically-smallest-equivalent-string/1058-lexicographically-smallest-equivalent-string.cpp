class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> adj(26); 
        for (int i = 0; i < s1.size(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(26, false);
        vector<char> rep(26); 

        for (int i = 0; i < 26; i++) {
            if (!visited[i]) {
                queue<int> q;
                vector<int> group;

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    group.push_back(node);

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                char minChar = 'z';
                for (int ch : group) {
                    minChar = min(minChar, (char)(ch + 'a'));
                }

                for (int ch : group) {
                    rep[ch] = minChar;
                }
            }
        }

        string result = "";
        for (char ch : baseStr) {
            if (rep[ch - 'a'] != 0) {
                result += rep[ch - 'a'];
            } else {
                result += ch;
            }
        }

        return result;
    }
};