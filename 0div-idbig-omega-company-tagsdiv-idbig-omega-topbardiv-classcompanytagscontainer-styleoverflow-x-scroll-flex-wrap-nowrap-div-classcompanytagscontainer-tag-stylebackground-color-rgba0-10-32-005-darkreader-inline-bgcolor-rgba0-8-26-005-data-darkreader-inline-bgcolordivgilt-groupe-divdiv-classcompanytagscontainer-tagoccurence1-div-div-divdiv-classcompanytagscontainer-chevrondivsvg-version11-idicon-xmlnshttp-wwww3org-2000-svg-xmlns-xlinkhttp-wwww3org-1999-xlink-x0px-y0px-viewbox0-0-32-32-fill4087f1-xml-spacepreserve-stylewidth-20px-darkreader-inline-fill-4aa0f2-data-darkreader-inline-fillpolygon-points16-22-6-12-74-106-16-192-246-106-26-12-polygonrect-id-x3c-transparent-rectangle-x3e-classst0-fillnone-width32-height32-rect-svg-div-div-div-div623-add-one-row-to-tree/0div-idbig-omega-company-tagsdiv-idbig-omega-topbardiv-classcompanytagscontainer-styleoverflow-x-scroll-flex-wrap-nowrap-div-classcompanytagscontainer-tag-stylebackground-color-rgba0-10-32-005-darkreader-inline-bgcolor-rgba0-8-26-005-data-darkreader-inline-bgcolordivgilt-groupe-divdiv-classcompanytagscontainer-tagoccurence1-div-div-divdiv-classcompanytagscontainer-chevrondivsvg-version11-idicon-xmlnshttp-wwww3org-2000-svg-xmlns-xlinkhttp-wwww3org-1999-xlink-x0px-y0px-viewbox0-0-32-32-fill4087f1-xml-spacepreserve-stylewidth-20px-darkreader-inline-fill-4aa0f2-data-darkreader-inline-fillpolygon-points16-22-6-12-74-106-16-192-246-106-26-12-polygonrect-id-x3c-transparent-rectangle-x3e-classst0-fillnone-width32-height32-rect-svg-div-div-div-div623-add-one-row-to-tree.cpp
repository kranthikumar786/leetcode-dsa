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
    TreeNode* addOneRow(TreeNode* root, int val, int depth, int level = 1) {
         if(!root)
            return NULL;
        if(level == 1 && depth == 1) {
            TreeNode* node1 = new TreeNode(val);
            node1->left = root;
            return node1;
        }
          int givenLevel = depth, curLevel = 1;
          queue<TreeNode*>q;
          q.push(root);
           bool isOneRowAdded = 0;
          while ( !q.empty() ) {
                 curLevel++;
                 int s = q.size();
                 while (s--) {
                     TreeNode* CurNode = q.front();
                      q.pop();
                      if (curLevel == givenLevel) {  
                          TreeNode* NodeL = new   TreeNode(val);
                          NodeL->left = CurNode->left;
                          CurNode->left = NodeL; 
                          
                          TreeNode* NodeR = new TreeNode(val);
                          NodeR->right = CurNode->right;
                          CurNode->right = NodeR;
                        
                          isOneRowAdded = 1;
                      }
                    else {
                          if (CurNode->left) {
                              q.push(CurNode->left);
                          }
                          if (CurNode->right) {
                              q.push(CurNode->right);
                          }
                    }   
                 }
               if ( isOneRowAdded ) {
                     return root;
               }
          }
        return root;
    }
    };