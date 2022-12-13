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
   /* int isBalancedBst ( TreeNode* root ) {
          if ( !root ) {
                return 0;
          }
          int left  = isBalancedBst( root->left);
          int right = isBalancedBst( root->right);   
         if ((left == -1 || right == -1) || abs(left - right) > 1 ){
                retrun -1;
         }
        return max(left , right) + 1;
    }*/
    vector<int>bst;
    void dfs (TreeNode * root){
         if( !root ){
              return ;
         }
        dfs(root->left);
        bst.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* fn(vector<int>bst,int l,int h) {
          if ( l>h) {
               return NULL;
          }
         if ( l == h ) {
               return new TreeNode(bst[l]);
         }
         int m = ( l + h )>>1;
        TreeNode * node = new TreeNode(bst[m]);
        node->left = fn(bst,l,m-1);
        node->right = fn(bst,m + 1, h);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return fn(bst,0,bst.size()-1);   
    }
};
/*
TreeNode * orignal = root;   
          int l = isBalancedBst(root); 
        while ( l == -1) {
               
             
             1 
               2 
                  3
                    4 
                     
               one step to root->right:
               check it is having left child :
            No : then make root as current root->left and make  current root as Main root
                 
            
                TreeNode * cur = root ;
                 
              cur = cur->right;
               if ( !cur->left ) {
                  cur->left = root;
                   root = cur;
                    l = isBalancedBst(root);
                     continue;
               }
            
            
            
            
            
                
                 
                 
            
            
            
               
               
               
           }
        return  root;
        
        
      
    3 cases for treemodification :
          what if node conatins 
               1)left node and right node :
               2) only left node
               3) only right node.    
        
          Given BST :
             Write a function to check it is balanced or not ..?
             if not Balanced BST
              I have to convert it to balanced Bst :
               convertion process :
                  If root  right side vallues are eligble to become a root :
                   so 
                   
               Then if not go for modification:
        */
        