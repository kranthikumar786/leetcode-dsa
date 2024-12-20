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
    void travesrse(TreeNode* Lroot , TreeNode* Rroot, int depth) {
        
          if(!Lroot || !Rroot){return;}
         if(depth%2 == 0){
             swap(Lroot->val, Rroot->val);
         }
        travesrse(Lroot->left, Rroot->right,depth+1);
        travesrse(Lroot->right,Rroot->left, depth+1);
        return;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        travesrse(root->left , root->right,0);
           return root;
        /*
          idea is while swapping i have to get the depth as well     
            
             if(depth %2 == 0 && root) {
                
                swap(root->val, root->val);
             }
             traveser(root->left, root->right,depth+1):
             travese(root->right , root->left, depth+1);
        */
    }
};