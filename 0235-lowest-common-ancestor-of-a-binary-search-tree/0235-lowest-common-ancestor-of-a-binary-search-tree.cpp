/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        /*Approach 1:
                   Normal Recursion Traversal with cases : 
                     if either of p or q found in left or right  return left or right :

                      the moment both left and right are returning not null means found LCA
       */
        /*if ( !root || root == p || root == q) {
            return root;
       }
        
        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        return !left ? right : !right ? left : root;
        
        */
        
        /*
        Approach 2:
            Given input is BST so it is having relation with it's subtrees to move based on condtion so we will use that point and find LCA  using recusrion method
        */
        
        if ( !root || root == p || root == q) {
             return root;
        }
        
        if( root->val < p->val && root->val < q->val) {
              return lowestCommonAncestor(root->right,p,q);
        }
        
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    
    
      /*  
      approach2 logic using iterative method
      
       TreeNode * cur = root;
         while ( cur ){
             if (cur->val > p->val && cur->val > q->val) {
                   cur = cur->left;
             }
             else if(cur->val < p->val && cur->val < q->val) {
                     cur = cur->right;
             }
             else{
                 return cur;
             }
         }
        return cur;
    
       
     
       approach1Complexity = {
                 TimeComplexity = O(n),
                 SpaceComplexity =O(H)
       
       };
       approach2Complexity = {
                 TimeComplexity = O(logn),
                 SpaceComplexity =O(H)         
       };
       approach3Complexity = {
                 TimeComplexity = O(logn),
                 SpaceComplexity =O(1)       
       };
       
       Note : for approach1 & 2 Stack Space Considered!
        
       Thank You.
       Happy Coding!!!
        return findHelpFul ? pleaseUpvote : pleaseProvideCommentsForImprovements;   
       https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/discuss/2937331/C%2B%2BororEasy-oror-3-approaches/ 
       */
    }
};