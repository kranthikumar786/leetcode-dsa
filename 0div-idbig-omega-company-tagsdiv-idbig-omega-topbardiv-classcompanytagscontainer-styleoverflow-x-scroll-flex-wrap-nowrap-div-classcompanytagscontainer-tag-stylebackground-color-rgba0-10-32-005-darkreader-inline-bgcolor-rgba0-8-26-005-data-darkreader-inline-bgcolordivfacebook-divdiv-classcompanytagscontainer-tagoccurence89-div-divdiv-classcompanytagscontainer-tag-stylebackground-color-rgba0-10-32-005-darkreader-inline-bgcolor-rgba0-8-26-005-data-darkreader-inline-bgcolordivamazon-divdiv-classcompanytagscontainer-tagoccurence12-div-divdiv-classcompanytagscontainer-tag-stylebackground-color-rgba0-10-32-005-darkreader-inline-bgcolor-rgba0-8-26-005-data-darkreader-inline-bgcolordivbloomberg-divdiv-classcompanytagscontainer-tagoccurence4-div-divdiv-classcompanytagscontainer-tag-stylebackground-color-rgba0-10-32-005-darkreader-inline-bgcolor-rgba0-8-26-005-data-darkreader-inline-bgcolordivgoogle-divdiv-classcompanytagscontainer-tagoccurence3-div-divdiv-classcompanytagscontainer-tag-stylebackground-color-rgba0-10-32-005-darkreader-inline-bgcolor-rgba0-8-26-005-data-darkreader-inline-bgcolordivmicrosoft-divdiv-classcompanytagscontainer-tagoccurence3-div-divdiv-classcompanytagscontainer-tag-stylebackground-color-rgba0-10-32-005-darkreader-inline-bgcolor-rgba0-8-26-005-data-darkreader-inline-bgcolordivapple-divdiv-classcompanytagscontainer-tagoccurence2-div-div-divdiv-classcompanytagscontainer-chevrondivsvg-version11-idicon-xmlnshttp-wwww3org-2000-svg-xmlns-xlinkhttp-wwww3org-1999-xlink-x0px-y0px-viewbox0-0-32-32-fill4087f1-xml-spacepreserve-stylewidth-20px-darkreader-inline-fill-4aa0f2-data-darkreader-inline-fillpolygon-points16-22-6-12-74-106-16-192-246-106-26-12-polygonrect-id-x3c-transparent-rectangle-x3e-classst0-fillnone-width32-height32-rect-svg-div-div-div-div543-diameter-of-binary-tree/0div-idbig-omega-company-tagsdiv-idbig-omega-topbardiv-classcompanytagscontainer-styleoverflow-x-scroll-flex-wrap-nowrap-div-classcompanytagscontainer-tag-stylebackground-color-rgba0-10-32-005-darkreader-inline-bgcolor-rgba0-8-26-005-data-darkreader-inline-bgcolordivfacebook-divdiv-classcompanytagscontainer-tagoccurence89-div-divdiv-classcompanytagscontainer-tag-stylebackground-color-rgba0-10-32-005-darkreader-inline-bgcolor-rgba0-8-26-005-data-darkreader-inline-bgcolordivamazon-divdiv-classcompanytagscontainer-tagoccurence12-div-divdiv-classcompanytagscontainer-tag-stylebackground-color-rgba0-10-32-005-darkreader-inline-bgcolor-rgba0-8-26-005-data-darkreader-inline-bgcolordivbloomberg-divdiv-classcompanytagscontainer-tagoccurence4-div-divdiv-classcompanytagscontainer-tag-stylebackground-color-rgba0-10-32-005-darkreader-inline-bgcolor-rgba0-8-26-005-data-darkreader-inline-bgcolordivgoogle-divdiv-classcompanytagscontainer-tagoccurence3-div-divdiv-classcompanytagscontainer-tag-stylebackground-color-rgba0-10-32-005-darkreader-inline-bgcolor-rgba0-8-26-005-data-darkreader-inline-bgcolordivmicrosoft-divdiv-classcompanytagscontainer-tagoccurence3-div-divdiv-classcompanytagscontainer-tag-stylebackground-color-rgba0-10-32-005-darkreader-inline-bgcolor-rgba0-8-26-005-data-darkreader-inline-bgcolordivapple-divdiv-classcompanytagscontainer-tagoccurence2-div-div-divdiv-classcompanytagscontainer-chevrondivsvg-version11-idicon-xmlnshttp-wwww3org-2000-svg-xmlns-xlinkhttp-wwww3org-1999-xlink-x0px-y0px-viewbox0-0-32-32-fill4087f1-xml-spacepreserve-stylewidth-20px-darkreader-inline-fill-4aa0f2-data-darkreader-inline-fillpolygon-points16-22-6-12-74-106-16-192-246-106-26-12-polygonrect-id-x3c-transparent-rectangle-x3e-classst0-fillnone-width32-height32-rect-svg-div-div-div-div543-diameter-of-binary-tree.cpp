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
     int height(TreeNode *a,int &b)
     {  if(!a) return -1;
       int l=height(a->left,b);
       int r=height(a->right,b);
         
       b=max(b,l+r+2);
      return max(l,r)+1;
     }
    
    int diameterOfBinaryTree(TreeNode* root) {
      TreeNode * a=root;
       int b=0;
        height(a,b);
        return b;
    }
};