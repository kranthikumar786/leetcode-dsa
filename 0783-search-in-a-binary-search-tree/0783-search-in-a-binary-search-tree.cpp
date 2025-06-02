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
    TreeNode* searchBST(TreeNode* root, int val) {
         TreeNode* Root =  root;
          while( Root && Root ->val != val){
            Root = Root->val > val ? Root->left : Root->right;
          }
   return Root;
    }
};
/*
if(!root){return nullptr;}
    if(root->val == val){ // early exit: 
     return root;}
    // TreeNode* left1 = nullptr ;
    // TreeNode* right1 = nullptr;
    if(root->val > val) { 
       return  searchBST(root->left, val);
    }
    // if( left1 ){
    //  return left1;
    // }
    //right1 =  
    return searchBST(root->right,val);
   // return right1;
*/