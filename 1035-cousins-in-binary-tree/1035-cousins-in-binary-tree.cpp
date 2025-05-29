
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            bool foundX = false, foundY = false;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();

                // Check if left and right child are x and y (sibling check)
                if (node->left && node->right) {
                    int l = node->left->val, r = node->right->val;
                    if ((l == x && r == y) || (l == y && r == x)) {
                        return false; // same parent → not cousins
                    }
                }

                // Track if we found x or y
                if (node->val == x) foundX = true;
                if (node->val == y) foundY = true;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // After one level
            if (foundX && foundY) return true;  // same level, different parents
            if (foundX || foundY) return false; // one found → not cousins
        }

        return false;
    }
};




// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool isCousins(TreeNode* root, int x, int y) {
//        queue<TreeNode*>q;
//        q.push(root);
//       int level =  -1;
//        while(!q.empty()){
//          level++;
//          int levelL = q.size();
//           int cnt = 0;
//          for(int i = 0 ; i < levelL;i++) {
//               TreeNode *node = q.front();q.pop();
//                 if(node->left){
//                    if(node->left->val == x || node->left->val == y){
//                          cnt++;
//                    } 
//                    q.push(node->left);
//                 }
//             if(node->right){
//                    if(node->right->val == x || node->right->val == y){
//                          cnt++;
//                    } 
//                   q.push(node->right); 
//                 }
         
//           if(cnt >= 2){
//               return false;
//           }
//        }
//     }
//     return true;
// };