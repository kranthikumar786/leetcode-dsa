class Solution {
public:
    void help(int i, vector<int>& ans, int n) {
        if (i > n)
            return;
        ans.push_back(i);
        help(i * 10, ans, n);

        if (i % 10 != 9)
            help(i + 1, ans, n);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        help(1, ans, n);
        return ans;
    }
};