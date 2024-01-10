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
   int maxDistance = 0;
    int treaverseTree(TreeNode *root , int start) {
          int depth = 0;
         if( !root ){
             return depth;
         }
        
        int leftDepth = treaverseTree(root->left,start);
        int rightDepth = treaverseTree(root->right,start);
        
        if(root->val == start) {
            maxDistance = max(leftDepth , rightDepth);
            depth = -1;
        } else if(leftDepth >= 0 && rightDepth >= 0) {
            depth = max(leftDepth,rightDepth) + 1;
        } else{
             int distnace = abs(leftDepth) + abs(rightDepth);
             maxDistance = max(maxDistance,distnace);
            depth = min(leftDepth,rightDepth) - 1;
        }
        
return depth;    
    }
    int amountOfTime(TreeNode* root, int start) {
        treaverseTree(root,start);
        return maxDistance;
    }
};