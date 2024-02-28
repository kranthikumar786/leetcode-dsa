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
    int findBottomLeftValue(TreeNode* root) {
       
        if(root && !root->left && !root->right) {
             return root->val;
        }
        
        int ans = 0 ;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()>0) {
           int len = q.size();
            bool f = 0 ;
            while ( len-- ) {
             TreeNode* root1 = q.front();
                           q.pop();
                     if (!f){
                           ans = root1->val;
                            f = 1;
                     }
                if(root1->left) {
                    q.push(root1->left);
                  }
                if(root1->right) {
                    q.push(root1->right);
                }
            }  
        }
     return ans; 
    }
};

/*
Test Cases 
[2] = > pass = > Base Case 
[2,1,null,8] =  >pass = > left Skewed Binray Tree
[2,1,3]= > pass
[1,2,3,4,null,5,6,null,null,7] = > pass
[1,2,null,3,null,null,null,4] = > pass



*/