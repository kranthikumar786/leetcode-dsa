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
        int X_depth = -1,Y_depth=-2,X_parent = -1,Y_parent = -1;
    /*bool dfs(TreeNode *root,int x,int y, int depth) {
          if (!root) {
              return 0;
          }
          if ((X_depth == Y_depth) && (X_parent != Y_parent)) {
               return 1;
          }
          if(root->left && root->left->val == x || root->right && root->right->val == x) {
              X_depth = depth+1;
              X_parent = root->val;
              }
          if(root->left && root->left->val == y || root->right && root->right->val == y) {
              Y_depth = depth+1;
              Y_parent = root->val;
         }
        if (dfs(root->left,x,y,depth+1)||dfs(root->right,x,y,depth+1)) 
                 return 1;
    return 0;  
    }*/
    bool isCousins(TreeNode* root, int x, int y) {
     
        if(root && (!root->left || !root->right))
                return 0;
       queue<TreeNode*>q;
       q.push(root);
         int level = 0;
        while (!q.empty()) {
              int si = q.size();
                level++;
             while (si--) { 
            TreeNode *node =q.front();
                q.pop();
    if( (node->left && node->left->val == x) || (node->right && node->right->val == x)){
               X_parent = node->val;
               X_depth = level+1;
            } 
      if((node->left && node->left->val == y) || (node->right && node->right->val ==y)){
          Y_parent = node->val;
          Y_depth = level+1;
      }
       if(X_parent != Y_parent  && X_depth == Y_depth)
              return 1;
      if (node->left)
          q.push(node->left);
       if(node->right) 
           q.push(node->right);           
    }
            
 }
 return 0;       
        
        
        
        
        
        //  return dfs(root,x,y,0);
        /*if ((X_depth != Y_depth || X_parent == Y_parent))
                  return 0;
        return 1;
        */
        
        /*
       Approach is : 
               dfs with depth and find if either x or y found :
                         take depthe of that value and depth and y value and it's depth 
                           and parent of both 
                            if x || y not existing then return false:
                           if both parent is same return false:
                           if x's depth != y's depth return false:                  
       
       
       
       
       
       
        folow up:
          x and y is always exist ...?:
          
          
        test case:
         1)only root existing:
         2) skewed tree or pathological tree will leads to false  result:
         3) best case is 2 level perfect binary tree:
       
         ================= DFS START ====================================
          TC: 
             WORST CASE WITH FALSE RESULT:O(N) == O(H)
                                SKEWED TREES AND PATHOLOGICAL TREES        
             WORST CASE WITH TRUE RESULT: O(N) == O(H)
                       PERFECT BINARY TREES
                       
              avg case : find x and y in middle of tree then go for results:
              
              Best case: 
               at O(2)  2 nd level with  true results:
              at   O(1) 0 th level with false result:(only root existing no left,or right): 
          SC: 
           WORST CASE :
                       SAME AS TC:
            AVG CASE:
                 SAME AS TC
             BEST CASE:
                       o(1) with false results:
                       O(1) with true results: 
      ============================DFS END============================================                 
       
         
         
         
         
         
         
       
       
       */   
    }
};