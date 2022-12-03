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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>levelOr;
            if ( !root ){
                 return levelOr;
            }
         queue<TreeNode*>q;
         q.push(root);
       while ( !q.empty() ) {
           
             int size = q.size();
              vector<int>level;
             for (int i = 0 ; i < size ; i++ ){
                 
                      TreeNode * curNode = q.front();
                      q.pop();
                      level.push_back(curNode->val);    
                    if (curNode->left) {
                         q.push(curNode->left);
                    }
                    if(curNode->right) {
                        q.push(curNode->right);
                    }
             }
           
       levelOr.push_back(level);
       }
        return levelOr;
    }  
};      
        
/*class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>levelOr;
            if ( !root ){
                 return levelOr;
            }
         queue<TreeNode*>q;
         q.push(root);
         q.push(NULL);
         vector<int>level;
         while ( q.size() > 1) {
               TreeNode* curNode = q.front();
               q.pop();
               if ( curNode ) {
                 level.push_back( curNode->val );   
               if ( curNode ->left ){
                   q.push(curNode->left);
               }
               if (curNode ->right ){
                   q.push(curNode->right);
               }
             } else {
                   levelOr.push_back(level);
                    level = {};
                   q.push(NULL);
               }
          }
        levelOr.push_back(level);
       return levelOr;
    }
};
*/