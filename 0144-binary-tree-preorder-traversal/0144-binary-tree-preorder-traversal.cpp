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
/* approach1 ===== Recusrion ===== Start =====
class Solution {
public:
      vector<int>Pre;
     void PreOrder ( TreeNode* root ) {
         if ( !root ) {
              return ;
         }
         Pre.push_back(root->val);
         PreOrder(root->left);
         PreOrder(root->right);
     }
    vector<int> preorderTraversal(TreeNode* root) {
         PreOrder(root);
       return Pre;  
    }
};
approach1 = {
      TimeComplexity = O(n),
      SpaceComplexity = O(n) 
};
Note : implicit Stack Space Considerd

 approach1 ====== Recusrion =======End=========*/

class Solution {
public:
      vector<int>Pre;
vector<int> preorderTraversal(TreeNode* root) {
         if ( !root ){
              return Pre;
         }
        stack<TreeNode*>storeChildrens;
         storeChildrens.push(root);
        while ( !storeChildrens.empty()) {
                 TreeNode* node = storeChildrens.top();
                   storeChildrens.pop();
                 if ( node ) {
                     Pre.push_back(node->val);  
                 }
                 if ( node->right ) {
                     storeChildrens.push( node->right );
                 }
                 if ( node->left ) {
                      storeChildrens.push( node->left );
                 }
             }
       return Pre;  
    }
};



