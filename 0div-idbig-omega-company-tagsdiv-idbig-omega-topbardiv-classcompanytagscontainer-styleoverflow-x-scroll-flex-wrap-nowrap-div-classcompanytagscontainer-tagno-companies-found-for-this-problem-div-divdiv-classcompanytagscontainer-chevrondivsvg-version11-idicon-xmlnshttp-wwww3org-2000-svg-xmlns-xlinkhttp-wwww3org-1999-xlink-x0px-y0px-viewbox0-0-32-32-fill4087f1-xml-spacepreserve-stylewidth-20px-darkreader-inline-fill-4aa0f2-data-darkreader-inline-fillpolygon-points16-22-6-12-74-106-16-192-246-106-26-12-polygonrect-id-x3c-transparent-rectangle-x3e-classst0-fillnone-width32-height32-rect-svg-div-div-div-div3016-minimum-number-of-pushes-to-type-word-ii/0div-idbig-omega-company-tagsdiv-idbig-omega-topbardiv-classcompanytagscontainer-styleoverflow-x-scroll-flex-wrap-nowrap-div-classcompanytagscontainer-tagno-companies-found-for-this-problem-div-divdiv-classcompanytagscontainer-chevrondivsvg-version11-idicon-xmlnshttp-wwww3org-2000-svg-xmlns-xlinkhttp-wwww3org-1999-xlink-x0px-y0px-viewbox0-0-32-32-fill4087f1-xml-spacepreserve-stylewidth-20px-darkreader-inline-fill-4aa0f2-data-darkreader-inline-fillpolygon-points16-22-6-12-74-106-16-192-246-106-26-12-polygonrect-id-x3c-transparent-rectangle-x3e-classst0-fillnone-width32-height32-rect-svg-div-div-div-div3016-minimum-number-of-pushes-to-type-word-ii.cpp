class Solution {
public:
   int minimumPushes(string word) {
        unordered_map<int, int> count;
        for (char& c : word) {
            count[c - 'a']++;
        }
        vector<int> A;
        for (auto& c : count) {
            A.push_back(c.second);
        }
        sort(A.rbegin(), A.rend());
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            res += (i / 8 + 1) * A[i];
        }
        return res;
    }
};