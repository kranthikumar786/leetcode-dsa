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
 /* Approach1  ==== Recursion ================Start==================================
   class Solution {
public:
   
    vector<int>inOrder;
    
    void inOrderTr( TreeNode * root ) {
          if ( !root ){
                return;
          }
         inOrderTr(root->left);
         inOrder.push_back(root->val);
        inOrderTr(root->right);
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
         if ( !root ) {
             return { };
         }
          inOrderTr(root);
         return inOrder; 
    }
    
    
};

approach1Complexity = {
       TimeComplexity = O(n),
       SpaceComplexity = (n) for Skewed Trees 
};
Note :  Implicit  Stack considered for SpaceComplexity
 Approach 1 == Recusrion ==================================End =============================*/

/*Approach 2 === Stack + Iteration=========================Start ========================*/
 class Solution {
public:
    vector<int>inOrder;
      vector<int> inorderTraversal(TreeNode* root) {
         if ( !root ) {
             return { };
         }
         stack<TreeNode*> storeRightChild;
          while ( !storeRightChild.empty() || root ){
                 
                   while ( root ) {
                       storeRightChild.push( root );
                       root = root->left;
                   } 
                    root = storeRightChild.top();
                    storeRightChild.pop();
                    inOrder.push_back(root->val);               
                    root = root->right; 
          }  
          return inOrder; 
    }  
 };

/*approach2Complexity = {
       TimeComplexity = O(n),
       SpaceComplexity = O(n) for Skewed Trees  
};
Approach 2 ======Stack + Iteration ====================End =========================*/  






