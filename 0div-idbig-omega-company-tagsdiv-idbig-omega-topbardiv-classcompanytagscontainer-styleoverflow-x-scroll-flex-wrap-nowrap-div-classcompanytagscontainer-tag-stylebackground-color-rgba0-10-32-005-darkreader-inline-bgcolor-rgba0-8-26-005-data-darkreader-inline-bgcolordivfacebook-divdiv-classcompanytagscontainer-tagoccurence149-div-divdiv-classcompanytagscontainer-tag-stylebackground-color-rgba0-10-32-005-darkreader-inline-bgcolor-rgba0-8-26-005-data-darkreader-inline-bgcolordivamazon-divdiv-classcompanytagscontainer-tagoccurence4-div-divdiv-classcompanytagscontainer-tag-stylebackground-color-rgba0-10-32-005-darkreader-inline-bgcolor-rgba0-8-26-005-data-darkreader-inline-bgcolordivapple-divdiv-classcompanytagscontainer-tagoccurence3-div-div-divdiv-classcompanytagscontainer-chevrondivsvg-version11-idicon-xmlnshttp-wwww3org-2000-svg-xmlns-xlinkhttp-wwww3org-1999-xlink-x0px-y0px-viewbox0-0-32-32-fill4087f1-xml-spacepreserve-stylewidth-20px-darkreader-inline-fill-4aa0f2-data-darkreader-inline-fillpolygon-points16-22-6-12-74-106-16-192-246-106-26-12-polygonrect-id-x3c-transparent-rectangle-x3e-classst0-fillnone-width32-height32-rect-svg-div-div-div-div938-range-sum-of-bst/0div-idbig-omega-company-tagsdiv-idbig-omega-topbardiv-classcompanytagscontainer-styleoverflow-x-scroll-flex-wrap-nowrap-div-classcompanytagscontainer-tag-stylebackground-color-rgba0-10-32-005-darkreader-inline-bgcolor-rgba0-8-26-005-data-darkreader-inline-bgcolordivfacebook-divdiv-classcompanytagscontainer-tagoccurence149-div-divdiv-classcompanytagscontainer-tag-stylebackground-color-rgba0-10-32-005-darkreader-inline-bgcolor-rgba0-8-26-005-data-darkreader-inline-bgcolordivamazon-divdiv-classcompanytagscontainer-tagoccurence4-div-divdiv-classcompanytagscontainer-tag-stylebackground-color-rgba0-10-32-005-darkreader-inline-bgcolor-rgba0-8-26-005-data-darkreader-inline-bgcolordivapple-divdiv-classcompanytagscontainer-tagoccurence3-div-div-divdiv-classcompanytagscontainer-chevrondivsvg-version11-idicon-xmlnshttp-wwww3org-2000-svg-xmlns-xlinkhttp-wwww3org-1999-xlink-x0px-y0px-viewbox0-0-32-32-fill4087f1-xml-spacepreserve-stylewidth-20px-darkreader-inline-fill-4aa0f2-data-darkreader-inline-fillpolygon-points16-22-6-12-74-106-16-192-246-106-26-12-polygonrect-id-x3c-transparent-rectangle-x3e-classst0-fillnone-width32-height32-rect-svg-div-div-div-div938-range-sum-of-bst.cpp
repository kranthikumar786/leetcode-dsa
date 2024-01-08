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
 
      vector<int>ans;
    void Ans(TreeNode *root) {
         if(!root){
             return;
         }
        Ans(root->left);
        ans.push_back(root->val);
        Ans(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
      
       Ans(root);
      
        int ansRangeSum = 0;
    for(int i = 0 ; i < ans.size() ; i++) {
         if(ans[i]>= low && ans[i] <= high)
         ansRangeSum += ans[i];
    }    
      return ansRangeSum;  
    }
};