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
vector<int> largestValues(TreeNode* root) {
 
    if (!root) {
           return vector<int>{}; 
        }
    queue<TreeNode*>Q;
  Q.push(root);
vector<int>largestValuesInEachTreeRow;
  while(Q.size()){
    int maxEle = INT_MIN;
    int length = Q.size();
      while(length--){
      TreeNode* node = Q.front();Q.pop();
        maxEle = max(maxEle, node->val);
        if(node->left){
            Q.push(node->left);
        } 
         if(node->right){
            Q.push(node->right);
         }
      }
      largestValuesInEachTreeRow.push_back(maxEle);
  }
  return largestValuesInEachTreeRow;
    }
};