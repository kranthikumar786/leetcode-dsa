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
      int maxSum = INT_MIN;
    
    /*
    int subtreeSum( TreeNode * root ) {
        return !root ? 0 : root->val + subtreeSum(root->left) +subtreeSum(root->right);
    }
    void EverySubtree(TreeNode * root) {
          if ( !root ) {
                return ;
          }
     maxSum =max (root->val , max (subtreeSum(root), subtreeSum(root)));   
        EverySubtree (root->left);
        EverySubtree (root->right);    
        return;
    } 
    
    int maxPathsum(TreeNode * root) {        
    if( !root ) {
          return 0;
     }
      int left =  max (maxSum,maxPathsum(root->left);
      int right = maxPathsum(root->right);  
      maxSum = max(maxSum, left+right+root->val);
       return max(left,right)+root->val;
    }*/
    
    int maxPathsum(TreeNode *root ) {
          if ( !root ){
               return 0;
          }
          int leftMax = max(maxPathsum(root->left),0);
          int rightMax = max(maxPathsum(root->right),0);
          maxSum = max(maxSum, leftMax + rightMax+root->val);
          return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
         maxPathsum(root);
        return maxSum;
 }
};

/*
 Basic idea is  EverySubTreeSum then max ans : 
*/   



