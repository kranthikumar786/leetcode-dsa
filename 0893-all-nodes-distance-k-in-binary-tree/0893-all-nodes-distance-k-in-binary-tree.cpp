class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;

    void dfs(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        parentMap[node] = parent;
        dfs(node->left, node);
        dfs(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);  // build parent links

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        while (!q.empty() && k--) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parentMap[node] && !visited[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};



























// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:

//    unordered_map<TreeNode*,TreeNode*>parent;
//      void dfs(TreeNode* root , TreeNode* parent) {
//             if(!root){return;}
//             parent[root] = parent;
//            dfs(root->left,root);
//            dfs(root->right,root); 
//      }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         vector<int>visited(501,0);
//         queue<TreeNode*>Q;
//         Q.push(target);
//          while(!Q.empty() && k ) {
//                 k--;
//                 int level = Q.size();
//              for(int i = 0 ; i < level ; i++) {    
//                   TreeNode* node = Q.front();
//                   Q.pop();
//                  if(!visited[node->val]) {
//                     Q.push(parent[node]);
//                  }
//                   if(node->left){
//                      Q.push(node->left);
//                   }
//                   if(node->right){
//                     Q.push(node->right);
//                   } 
//              } 
//          }
//         vector<int>ans;
//         while(!Q.empty()){
//         TreeNode * node = Q.front();
//            Q.ppop();
//           ans.push_back(node->val);
//         }
//        return ans; 
//     }
// };