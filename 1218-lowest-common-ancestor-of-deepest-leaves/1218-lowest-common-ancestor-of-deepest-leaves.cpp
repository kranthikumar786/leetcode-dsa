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
    pair<TreeNode*, int> get(TreeNode* root1) {
        if (!root1) return {nullptr, 0};
        if (!root1->left && !root1->right) return {root1, 1};

        pair<TreeNode*, int> left = get(root1->left);
        pair<TreeNode*, int> right = get(root1->right);

        if (left.second == right.second) {
            return {root1, left.second + 1};
        } else if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        return {left.first, left.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return get(root).first;
    }
};
