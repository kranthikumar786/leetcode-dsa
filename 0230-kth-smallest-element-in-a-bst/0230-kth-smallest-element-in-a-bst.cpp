/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int &cnt, int &ans, int k, bool &found) {
        if (!root || found) return;
        solve(root->left, cnt, ans, k, found);
        if (found) return;
        cnt++;
        if (cnt == k) {
            ans = root->val;
            found = true;
            return;
        }
        solve(root->right, cnt, ans, k, found);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = -1;
        bool found = false;
        solve(root, cnt, ans, k, found);
        return ans;
    }
};
