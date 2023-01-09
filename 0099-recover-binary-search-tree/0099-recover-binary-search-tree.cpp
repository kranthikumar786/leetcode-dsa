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
    
    TreeNode * prev = NULL,*first = NULL, *second = NULL;
    
    void inorder(TreeNode * root ) {
         if ( !root ) {
              return ;
         }
        inorder(root->left);
        
        if (prev && root->val < prev->val) {
            
             if ( !first ) {
                  first = prev;
             }
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
     
       if ( !root ) {
            return ;
       }   
       inorder(root); 
         int t = first->val ; 
         first->val = second->val ; 
         second->val = t; 
      
        /*
          Bst -> 
          
          root->left->val <= root->val && root->right->val > root->val;
           1<=3 
            4>3
          =========================
            2 < 4  true but parent 4 is 3 so 2:
              so need to swap :
               exactly two values : 
               
                 root->right child subtree shoudnot conatins any less values if yes swap :
                 root->left child subtree shoundnot conains any greater values if yes swap:
                 TC:O(n*n):
                 
                 ex: 
                    3
                    
                    search in left :
                    
                    all values should be less if not swap root values with conditino false:
                    
                    Search in right :   
        */
    }
};