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
    TreeNode* recoverFromPreorder(string traversal) {
        
        vector<TreeNode *> st;
        for (int i = 0 , level ,val ; traversal[i] ; ) {
                                                         
           for( level = 0 ; traversal[i] == '-' ; i++ ) {
                     level++;
             }
            for ( val = 0 ; traversal[i] && traversal[i] != '-'; i++ ) {
                        val = val * 10 + traversal[i] - '0';
               }
           
          TreeNode * root = new TreeNode(val);
            while (st.size()> level)
                   st.pop_back();
                
             if ( !st.empty() ) {
                 
                  if (!st.back()->left ) {
                         st.back()->left = root;
                  } else{
                      st.back()->right = root;
                  }
             }
             st.push_back(root);
        }
      return st[0];
    }
};