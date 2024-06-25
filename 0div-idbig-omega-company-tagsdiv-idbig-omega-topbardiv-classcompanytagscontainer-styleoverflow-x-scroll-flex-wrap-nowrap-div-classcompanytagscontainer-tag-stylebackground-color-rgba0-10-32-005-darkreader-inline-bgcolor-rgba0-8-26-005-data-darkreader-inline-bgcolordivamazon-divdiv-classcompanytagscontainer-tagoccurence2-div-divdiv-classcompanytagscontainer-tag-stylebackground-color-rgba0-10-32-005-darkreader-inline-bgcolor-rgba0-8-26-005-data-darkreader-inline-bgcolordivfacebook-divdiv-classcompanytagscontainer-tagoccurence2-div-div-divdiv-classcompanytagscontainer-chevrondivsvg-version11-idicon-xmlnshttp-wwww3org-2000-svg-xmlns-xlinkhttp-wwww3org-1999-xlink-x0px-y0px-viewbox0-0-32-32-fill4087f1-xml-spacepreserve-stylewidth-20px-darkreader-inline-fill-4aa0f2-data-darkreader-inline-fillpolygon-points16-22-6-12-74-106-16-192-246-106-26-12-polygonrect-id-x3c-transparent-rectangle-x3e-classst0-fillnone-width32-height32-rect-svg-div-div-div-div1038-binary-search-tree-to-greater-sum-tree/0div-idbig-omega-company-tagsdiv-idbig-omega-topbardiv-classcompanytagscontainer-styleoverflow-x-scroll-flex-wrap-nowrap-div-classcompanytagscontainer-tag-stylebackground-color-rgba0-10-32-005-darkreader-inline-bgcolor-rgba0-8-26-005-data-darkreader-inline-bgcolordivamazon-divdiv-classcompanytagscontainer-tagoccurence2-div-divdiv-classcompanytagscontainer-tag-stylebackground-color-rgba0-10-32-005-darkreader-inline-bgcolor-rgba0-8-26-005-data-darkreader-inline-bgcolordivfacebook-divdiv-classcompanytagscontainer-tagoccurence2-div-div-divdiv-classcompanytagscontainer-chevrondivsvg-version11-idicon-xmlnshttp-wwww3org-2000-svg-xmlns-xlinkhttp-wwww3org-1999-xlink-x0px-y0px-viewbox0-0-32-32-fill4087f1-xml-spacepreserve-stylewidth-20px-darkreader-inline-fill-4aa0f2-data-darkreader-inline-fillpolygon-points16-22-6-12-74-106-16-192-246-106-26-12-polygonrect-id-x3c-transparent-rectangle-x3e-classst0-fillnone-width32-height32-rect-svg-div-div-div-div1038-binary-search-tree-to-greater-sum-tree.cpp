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
    
    void inOrder(TreeNode* root , int&sum) {
        
        if( root ) {
            
            inOrder(root->right,sum);
            sum+= root->val;
            root->val = sum;
            inOrder(root->left, sum);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        inOrder(root,sum);
        return root;
    }
};