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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
          unordered_map<int, TreeNode*>nodes;
          unordered_map<int,bool>isChild;
        vector<vector<int>> vi = descriptions; 
        for ( auto v : vi ) {
            
            if ( nodes.count( v[0] ) == 0){
                nodes[v[0]] = new TreeNode(v[0]);
            }
            if ( nodes.count( v[1]) == 0){
                 nodes[v[1]] = new TreeNode(v[1]);
            }
           if ( v[2] == 1) {
               nodes[v[0]]->left = nodes[v[1]];
           }else {
               nodes[v[0]]->right = nodes[v[1]];
           } 
            
           isChild[v[1]] = 1; 
        }
        
        TreeNode* ans = NULL;
        
        for (auto &v : vi) {
            
            if ( isChild[v[0]] != 1) {
                 ans = nodes[v[0]];
                  break;
            }
        }
        return ans;
        
        
    }
};
     