/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       /*if ( !root || root == p || root == q) {
            return root;
       }
        
        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        return !left ? right : !right ? left : root;
        
        */
        
       TreeNode * cur = root;
         while ( cur ){
             if (cur->val > p->val && cur->val > q->val) {
                   cur = cur->left;
             }
             else if(cur->val < p->val && cur->val < q->val) {
                     cur = cur->right;
             }
             else{
                 return cur;
             }
         }
        return cur;
    }
};