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
/*====================approach1 === PreOrderTraversal ====Start ============
/*approach1
   -> PreOrder Traversal of Tree
   -> Reverse level values if level is odd then return
 */
class Solution {
public:
     vector<vector<int>>ziglevel;
     void PreOrder(TreeNode * root , int cnt) {
           if( !root ) {
                 return;
           }
           if ( ziglevel.size() == cnt ){
                  ziglevel.push_back(vector<int>());
           }
          ziglevel[cnt].push_back(root->val);
          PreOrder(root->left,cnt + 1);
          PreOrder(root->right,cnt + 1);
     }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          if ( !root ){
               return ziglevel;
          }
        PreOrder(root,0);
        for ( int i = 1 ; i < ziglevel.size() ; i += 2 ) {
                reverse(ziglevel[i].begin(),ziglevel[i].end());
        }
         return ziglevel;
    }
};

/*
====================approach1 === PreOrderTraversal ==== End ============*/