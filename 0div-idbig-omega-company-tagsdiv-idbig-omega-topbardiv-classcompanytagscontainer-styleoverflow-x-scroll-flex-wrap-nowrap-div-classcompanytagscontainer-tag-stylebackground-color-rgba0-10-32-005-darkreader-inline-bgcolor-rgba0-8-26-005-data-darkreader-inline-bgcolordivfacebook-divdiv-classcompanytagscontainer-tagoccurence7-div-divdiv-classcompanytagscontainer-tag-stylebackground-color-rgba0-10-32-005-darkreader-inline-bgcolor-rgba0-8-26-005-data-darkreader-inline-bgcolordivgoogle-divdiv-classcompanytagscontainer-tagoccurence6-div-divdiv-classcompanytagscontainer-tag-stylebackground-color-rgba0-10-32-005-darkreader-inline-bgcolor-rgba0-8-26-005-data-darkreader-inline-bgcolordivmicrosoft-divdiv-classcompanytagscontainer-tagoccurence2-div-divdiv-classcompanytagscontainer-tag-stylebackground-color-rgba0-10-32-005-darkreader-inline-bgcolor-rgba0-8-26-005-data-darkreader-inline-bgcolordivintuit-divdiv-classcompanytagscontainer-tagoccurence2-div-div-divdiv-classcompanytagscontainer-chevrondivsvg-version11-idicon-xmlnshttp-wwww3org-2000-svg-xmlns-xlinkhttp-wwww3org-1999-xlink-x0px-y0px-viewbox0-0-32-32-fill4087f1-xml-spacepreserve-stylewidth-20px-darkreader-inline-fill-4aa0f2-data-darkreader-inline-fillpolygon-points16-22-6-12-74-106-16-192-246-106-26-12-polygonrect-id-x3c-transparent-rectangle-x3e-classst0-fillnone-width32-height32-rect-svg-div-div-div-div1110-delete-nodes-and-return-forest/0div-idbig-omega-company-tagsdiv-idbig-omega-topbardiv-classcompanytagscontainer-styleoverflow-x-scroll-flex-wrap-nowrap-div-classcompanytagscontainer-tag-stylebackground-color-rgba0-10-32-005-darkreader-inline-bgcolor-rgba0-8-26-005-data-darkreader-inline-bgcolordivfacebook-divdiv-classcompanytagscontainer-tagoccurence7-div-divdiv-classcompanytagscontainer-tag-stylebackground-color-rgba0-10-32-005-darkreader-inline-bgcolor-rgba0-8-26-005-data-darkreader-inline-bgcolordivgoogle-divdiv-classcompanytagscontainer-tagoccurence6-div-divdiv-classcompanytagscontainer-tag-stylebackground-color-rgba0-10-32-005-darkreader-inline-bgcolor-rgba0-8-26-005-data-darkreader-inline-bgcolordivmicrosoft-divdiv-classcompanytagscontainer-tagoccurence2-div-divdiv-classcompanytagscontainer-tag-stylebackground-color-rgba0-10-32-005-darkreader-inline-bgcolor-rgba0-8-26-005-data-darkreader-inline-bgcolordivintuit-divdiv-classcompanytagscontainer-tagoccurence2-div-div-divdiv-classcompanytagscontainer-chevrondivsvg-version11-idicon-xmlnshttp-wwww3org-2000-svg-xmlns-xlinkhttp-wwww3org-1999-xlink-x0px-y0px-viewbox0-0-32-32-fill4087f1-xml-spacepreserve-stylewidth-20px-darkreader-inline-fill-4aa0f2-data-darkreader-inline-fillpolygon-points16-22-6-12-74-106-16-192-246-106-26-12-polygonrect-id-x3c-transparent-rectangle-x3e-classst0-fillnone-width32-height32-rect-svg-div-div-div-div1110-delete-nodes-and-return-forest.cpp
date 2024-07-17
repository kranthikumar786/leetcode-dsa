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
      unordered_map<int,int>De;
       vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode * node ,bool isRoot) { 
        if ( !node ){
            return NULL;
        }
        bool deleted = (De.find(node->val) !=  De.end());
        if ( isRoot && !deleted ) { 
            ans.push_back(node);
        }
        node->left = dfs(node->left,  deleted);
        node->right =  dfs(node->right, deleted);
        return deleted ? NULL : node;
    } 
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       for ( auto v : to_delete){
             De[v]++;
       }  
        dfs(root,true);
        return ans;   
        
      }
};