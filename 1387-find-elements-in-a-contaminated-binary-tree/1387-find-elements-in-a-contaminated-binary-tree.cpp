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
class FindElements {
public: 
  TreeNode* Lroot = NULL;
  unordered_map<int,int>TreeValues;
     void DFS(TreeNode * root, int level){
           if(!root ) {
              return ;
           }
         root->val = level;
         TreeValues[level] = 1;
          if( root->left ){
            DFS(root->left ,2*(level) +1); 
          } 
           if( root->right ){
            DFS(root->right, 2*(level) + 2);
           }
     }
    FindElements(TreeNode* root) {
    TreeNode * Lroot = root;
    DFS(Lroot,0);
    }
    bool find(int target) {
       return (TreeValues.find(target) != TreeValues.end());
    }
};

//   bool findTarget(int target, TreeNode* root) {
          
    //   }
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
 /*

         10 : 
        2*x + 1 , 2*x + 2 : 
        1, 2 : 
  now i i have to chose to go right directly no left...
    
        /*
           0 : 
         1   2 
       3  4 5  6 
           \ 
            10 
        */