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
    int findHeight( TreeNode* root ) {
          if ( !root ){
                return 0;
          }
         int leftHeight = findHeight(root->left);
         int rightHeight = findHeight(root->right);
        return max(leftHeight,rightHeight)+1;
    }
    void generateTree(vector<vector<string>>&res, TreeNode* root, int curLevel, int low,int high){
              if ( !root ) {
                   return ;
              }
             int mid = (low + high)>>1;
            res[curLevel][mid] = to_string(root->val);
          generateTree(res,root->left,curLevel + 1, low, mid-1);
          generateTree(res,root->right,curLevel + 1, mid+1, high);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int height = findHeight(root);
         int width = pow(2,height) - 1;  
        vector<vector<string>>res(height,vector<string>(width,""));
         generateTree(res,root,0,0,width);
        return res;
    }
};