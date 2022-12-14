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
        /*
        Messi Code 
        int n = descriptions.size();
         bool isroot = 0;
        for (int i = 0 ; i < n ; i++ ) {
              if( mp.find(descriptions[i][0])) {
                 
                  pair<bool,TreeNode*> p  =  mp[descriptions[i][0]];    
                  if( desc[i][2]){
                         cur->left = new TreeNode(desc[i][1]);
                   }
                  else{
                        cur->right = new TreeNode(desc[i][2]);
                  }
       mp[desc[i][0]] = cur;          
                  
        else {
           TreeNode * node = new TreeNode(desc[i][j]);
                    if ( desc[i][j+2]) {
                         node ->left = new TreeNode (desc[i][j+1]);
                    } else {
                        node->right = new TreeNode(desc[i][j+1]);
               }
           mp[desc[i][j]] = node; 
        }
         
                  20 <-> it's tree:
             20 already presetn take it and check left or right :
               again pushinto map:
        
            if not found in map :
               create new one:   
            */    