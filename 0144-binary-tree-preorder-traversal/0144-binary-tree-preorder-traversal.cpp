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
approach1:
  -> first visit root node 
  -> then first left child then right child vist
  -> do above steps Recursively to root becomes NULL
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

/* approach2 ==== Iterativ + Stack ========== Start ==========
 Approach2:
      -> First Visit root node then go for childrens if exists:
      -> Here traversing right child first then left child becuase of Stack Data Structure Behaviour in terms of push(),pop()
      -> do iteratively above to steps till storeChildrens Stack empty()    
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
approach2Complexity = {
      TimeComplexity = O(n),
      SpaceComplexity = O(n)  for Skewed Trees
};
 approach2 ==== Iterativ + Stack ========== End ==========*/

/*approach3 ==== Morris PreOrder Traversal ========== Start ==========
  approah3 :
      -> connect the rightside childrens first without lose
      -> visit root val
      -> then move to left child
*/
class Solution {
public:
    vector<int>Pre;
    vector<int> preorderTraversal(TreeNode* root) {
          if ( !root ){
               return Pre;
          }
        while ( root ) {
            if ( root -> left ) {
                TreeNode* prece = root -> left;
                while ( prece -> right &&  prece -> right != root) {
                    prece = prece -> right;
                }
                if ( !prece -> right ) {
                    prece -> right = root;
                    Pre.push_back(root -> val);
                    root = root -> left;
                } else {
                    prece -> right = NULL;
                    root = root -> right;
                }
            } else {
                Pre.push_back(root -> val);
                root = root -> right;
            }
        }
        return Pre;
    }
};

/*
approach3Complexity = {
       TimeComplexity  = O(n),
       SpaceComplexity = O(1)
};

approach3 ==== Morris PreOrder Traversal ========== End ========== */
/*
 Thank You.
 Happy Coding !!!.
return findHelpFul ? pleaseUpVote : pleaseProvideCommentsForImprovements;

https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/2874355/C%2B%2B-oror-Easy-oror-3-Approaches
*/