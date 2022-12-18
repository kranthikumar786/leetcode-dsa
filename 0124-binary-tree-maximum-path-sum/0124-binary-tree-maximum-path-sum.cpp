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
      int max1 = max (root->val , max (max (0,subtreeSum(root) + root->val), max(0,subtreeSum(root)+root->val)));   
       maxSum = max(max1,maxSum); 
        EverySubtree (root->left);
        EverySubtree (root->right);    
        return;
    } 
    
    int maxPathsum(TreeNode *root ) {
      EverySubtree(root);
    return maxSum;
   }};
 /*
 approach1Complexity = {
          TimeComplexity = O(n^2),
          SpaceComplexity =O(Height)
 };
 */   
 /*
  Basic idea is  EverySubTreeSum then max ans : 
   four posssibilities: 
    1) only root itself (if left and right sums are negative we take only zero)
    2) root + left (if right Subtree Sum is negative take only left and for right zero)
    3) root+ right (if left subtree sum is negative take only right and for left zero)
    4) root + left+ right: (if both subtrees sum is + then take both of them)
  do recursively   
  */  
    int maxPathsum(TreeNode *root ) {
          if ( !root ){
               return 0;
          }
          int leftMax = max(maxPathsum(root->left),0);
          int rightMax = max(maxPathsum(root->right),0);
          maxSum = max(maxSum, leftMax + rightMax + root->val);
          return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
         maxPathsum(root);
        return maxSum;
 }
};
/*
approachComplexity = {
          TimeComplexity  = O(n),
          SpaceComplexity = O(Height)  
};
*/
/*
Thank You
Happy Coding !!!
 return findHelpful ? pleaseUpvote : pleaseProvideCommentsForImprovements;   

https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/2924677/C%2B%2B-oror-O(n)-oror-PostOrder
*/