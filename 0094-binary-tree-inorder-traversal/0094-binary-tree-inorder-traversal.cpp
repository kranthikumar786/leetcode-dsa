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

/*Approach 2 === Stack + Iteration=========================Start ========================
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

approach2Complexity = {
       TimeComplexity = O(n),
       SpaceComplexity = O(n) for Skewed Trees  
};
Approach 2 ======Stack + Iteration ====================End =========================*/  

/*Approach 3 ====  Morris's InOrder Traversal =============Start======================*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
         if ( !root ) {
             return { };
         }
         vector<int>inOrder;
     TreeNode* cur = root;
          while ( cur ) {
               if ( cur->left ) {
                   TreeNode * pre = cur->left;
                   while (pre->right && pre->right != cur ) {
                         pre = pre->right;
                   }
                   if ( !pre->right ) {
                       pre->right = cur;
                         cur = cur->left;
                   } 
                   else {
                         pre->right = NULL; // back to Original Tree Structure
                        inOrder.push_back(cur->val);
                          cur = cur->right;
                   }
                   
               } else {
                   
                   inOrder.push_back(cur->val);
                     cur = cur->right;
               }
          }
     return inOrder; 
    }
}; 
/*approach3Complexity = {
       TimeComplexity = O(n),
       SpaceComplexity = O(1)
};

Approach3 =========Morris's InOrder Traversal =============End========================*/
/*
Thank You.
Happy Coding!!!.
 return findHelpFul ? pleaseUpVote : pleaseProvideCommentsForImprovements; 
https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/2874197/C%2B%2B-oror-Easy-oror-3Approaches
*/




