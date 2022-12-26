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

/*
if ( !root){
             return NULL;
           }
         root->left  = deleteNode(root->left,key);
         root->right = deleteNode(root->right,key);
            if ( root->val == key && root->right ) {
                     return root->right;
          }
          if ( root->val == key && root->left ) {
                   return root->left;
          }
        if ( root->val == key && !root->left && !root->right ){
                     return NULL;
          }
        return root; 

 Problem with PostOrder traverrsal in this problem is :
  for example 1: 
  3 and it's childrens are deleting.
  even not correct way for BST s
Correct way is to find what is correct place to attach it's left child is imp Point Here.
*/
class Solution {
public:
     TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) 
                root->left = deleteNode(root->left, key);    
            else if(key > root->val) 
                root->right = deleteNode(root->right, key);       
            else {
                if(!root->left && !root->right) return NULL;          
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;                                            
                TreeNode* t = root->left;                        
                while( t->right ) 
                      t = t->right;     
                root->val = t->val;                            
                root->left = deleteNode(root->left, t->val);
            }
        return root;
    }   };

/*


Complexity = {
        TimeComplexity = O(n) (Skewed Trees),
        SpaceComplexity =O(n) Stack for Skewed Trees
};
Thank You.
Happy Coding!!!
return findHelpFul ? pleaseUpvote : pleaseProvideCommentsForImprovements;
https://leetcode.com/problems/delete-node-in-a-bst/discuss/2954952/C%2B%2B-oror-PostOrder-oror-easy
*/