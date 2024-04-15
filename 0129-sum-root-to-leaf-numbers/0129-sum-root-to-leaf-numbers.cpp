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
    void dft(TreeNode* root, int val, int& sum)
    {
        if (root == nullptr)
            return;
        
        val = val*10 + root->val;
        
        dft(root->left, val, sum);
        dft(root->right, val, sum);
        
        if (root->left == nullptr and root->right == nullptr)
            sum += val;
    }
public:
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        
        dft(root, 0, sum);
        
        return sum;
    }
};