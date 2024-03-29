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
    vector<int> postorderTraversal(TreeNode* root) {
        if ( !root ){
              return { };
        }
         vector<int>Post; 
        /*(stack <TreeNode*> st;
        st.push(root);
         while ( !st.empty() ){
              TreeNode* node = st.top();
                  st.pop();
              if (node){
                  Post.push_back( node->val); 
              }
             if (node->left) {
                   st.push(node->left);
              } 
             if (node->right) {
                  st.push(node->right);
              }
         }
        reverse(Post.begin(),Post.end());
        */
        
         TreeNode * cur = root;
           while ( cur ) {
               
                if( cur->right ) {
                    
                     TreeNode * prece = cur->right;
                      
                     while ( prece->left && prece ->left != cur ){
                               prece = prece->left;
                     }
                      if ( prece->left) {
                          prece ->left = NULL ;
                           cur = cur->left;
                      }
                    else {
                        
                         Post.push_back(cur->val);
                          prece ->left = cur;
                          cur = cur->right;
                    }
                } else {
                        Post.push_back(cur->val);
                         cur = cur->left;
                }
           }
          reverse(Post.begin(), Post.end());
        return Post;
    }
};