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

unordered_map<TreeNode*, TreeNode*> parentMap;
    void dfs(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        parentMap[node] = parent;
        dfs(node->left, node);
        dfs(node->right, node);
    }

    TreeNode* dfsFind(TreeNode*root, int s){
            if(!root){
                 return root;
            }
           if(root->val == s){
              return root;
           } 
          TreeNode*left = dfsFind(root->left,s);
          TreeNode*right = dfsFind(root->right,s);
          return (left != nullptr ? left :right);  
    }
    int amountOfTime(TreeNode* root, int start) {
         dfs(root, nullptr); 
        unordered_map<TreeNode*, bool> visited;
         TreeNode* st = dfsFind(root,start);
        queue<TreeNode*> q;
        q.push(st);
        visited[st] = true;
        int result = -1 ;
        while (!q.empty()) {
            int levelSize = q.size();
            result++;
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
        return result;
    }
};