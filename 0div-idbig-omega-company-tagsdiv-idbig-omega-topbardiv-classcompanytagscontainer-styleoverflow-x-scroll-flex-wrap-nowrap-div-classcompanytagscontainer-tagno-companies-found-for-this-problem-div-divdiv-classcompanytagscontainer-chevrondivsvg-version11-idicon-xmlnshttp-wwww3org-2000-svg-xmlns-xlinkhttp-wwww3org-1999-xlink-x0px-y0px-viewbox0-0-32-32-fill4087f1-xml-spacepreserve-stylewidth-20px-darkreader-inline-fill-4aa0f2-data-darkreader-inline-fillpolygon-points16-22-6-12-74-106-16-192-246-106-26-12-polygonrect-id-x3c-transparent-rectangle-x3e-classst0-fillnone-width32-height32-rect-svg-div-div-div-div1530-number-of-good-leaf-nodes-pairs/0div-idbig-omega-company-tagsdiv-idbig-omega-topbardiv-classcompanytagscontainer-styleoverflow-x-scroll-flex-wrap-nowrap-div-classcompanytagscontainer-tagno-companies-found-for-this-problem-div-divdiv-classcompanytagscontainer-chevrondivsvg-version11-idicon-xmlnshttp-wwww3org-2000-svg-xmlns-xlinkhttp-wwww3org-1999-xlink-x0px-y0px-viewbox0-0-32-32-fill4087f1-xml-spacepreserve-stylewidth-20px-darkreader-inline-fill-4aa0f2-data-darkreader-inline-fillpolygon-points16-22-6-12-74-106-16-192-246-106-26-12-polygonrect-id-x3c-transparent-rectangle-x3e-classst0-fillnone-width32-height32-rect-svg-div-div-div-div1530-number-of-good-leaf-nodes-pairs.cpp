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
      int cnt = 0 ;
    vector<int> leafNodes( TreeNode* root , int dist ) {
        
         if (  !root ) {
               return { };
         }
        auto left  = leafNodes (root->left,dist);
        auto right = leafNodes (root->right,dist);
          vector<int>res;
         if ( left.size() == 0  && right.size() == 0){
               res.push_back(1);
              return res;
         }
        
        for (int  lefts = 0 ; lefts < left.size(); lefts++ ) {
             
              for (int rights = 0 ; rights < right.size() ; rights++ ) {
                  
                    if ( left[lefts] + right[rights] <= dist ){
                              cnt++;
                    }
              }
        }
        
        for ( auto x : left ) {
               res.push_back(x+1);
        }
        for (auto y : right) {
            res.push_back(y+1);
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
         if ( !root ) {
              return 0;
         }
        leafNodes(root,distance);
        
       return cnt; 
    }
};