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
approach1Complexity = {
       TimeComplexity  =  O(n),
       SpaceComplexity =  O(n) for Skewed Trees
};
*/
/*====================approach1 === PreOrderTraversal ==== End ============*/
/*====================approach2 === LevelOrderTraversal ==== Start ============
approach2
 ->  push root and NULL into queue
 -> where NULL represent each level end
 -> if it's odd level then revese elements 
 -> append level values into respective level   
 */
class Solution {
public:
     vector<vector<int>>ziglevel;
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          if ( !root ){
               return ziglevel;
          }
        queue<TreeNode*>q;
       q.push(root);
       q.push(NULL);
        int i = 0;
         vector<int>level;
     while ( q.size() > 1 ) {
            TreeNode* curNode = q.front();
             q.pop();
              if ( curNode ) {
                level.push_back(curNode->val);  
                if( curNode->left ){
                   q.push(curNode->left);
                }  
                if ( curNode ->right ) {
                   q.push( curNode->right );
                }     
              } else {
                   if (i&1) {
                        reverse (level.begin(),level.end());
                   }  
                  ziglevel.push_back(level);
                     level = {};
                     i++;
                  q.push(NULL);
              }
     }
      if(i&1) {
        reverse(level.begin(),level.end());  
      }
      ziglevel.push_back(level);
   return ziglevel;
 }
};
/*
approach2Complexity = {
       TimeComplexity = O(n),
       SpaceComplexity =O(pow(2,h)-1) for Perfect Binary Tree  
};
*/
/*====================approach2 === LevelOrderTraversal ==== End ============*/
/*
 Thank You.
 Happy Coding!!!.
 return findHelpFul ? pleaseUpVote : pleaseProvideCommentsForImprovemts; 
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/2874538/C%2B%2B-ororEasy-oror-DFS-oror-BFS
*/




