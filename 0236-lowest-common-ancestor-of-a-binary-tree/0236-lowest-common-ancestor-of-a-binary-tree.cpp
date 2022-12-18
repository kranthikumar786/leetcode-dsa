/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    /*
       approach1 : PreOrderTraversal (Top to Down)  
              -> Start from root and check where node is existing 
              -> in process store the path (Ancestor(s) for a given node
              -> if node is not existing in that path remove last node
             -> then traverse the p ,q ancestors last matching value becomes LCA of P and Q:   
    */
    bool findAncestors(TreeNode* root, TreeNode* node, vector<TreeNode*>&p) {
          if ( !root ) {
               return 0;
          }
          if ( root == node ) {
              p.push_back(node);  
              return 1;
          }
        p.push_back(root);
        bool found = findAncestors(root->left,node,p) || findAncestors(root->right,node,p);
         
         if ( !found ) {
            p.pop_back(); 
             return 0;
         }     
        return 1;
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*>AncestorsP,AncestorsQ;
        findAncestors(root,p,AncestorsP);
      findAncestors(root,q,AncestorsQ);
      TreeNode * LCA = NULL;
        int i = 0 ;
        while( i < AncestorsP.size() && i <AncestorsQ.size() ){
              if (AncestorsP[i] == AncestorsQ[i]) {
                   LCA = AncestorsP[i];
              }
            i++;
        }
        return LCA;
}
};
/*
approach1Complexity = {
         TimeComplexity = O(n)+ O(n) + O(max(psize(),q,size())) = O(n),
         SpaceComplexity = O(n)
};
Note : Stack Space Not Considered
*/
/*
Approach2 : PostOrder(Bottom to Top) 
       -> 4 cases : 
          1 ) p,q are in same sub tree:
          2 ) p  is  in leftSubtree:
          3 ) q  is  in rightSubtree:
          4 ) root it self can conatins either p or q :
          
   /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  
        if ( !root || root == p || root == q) {
           return root;
      }   
        TreeNode * left  = lowestCommonAncestor(root->left,p,q);
        TreeNode * right = lowestCommonAncestor(root->right,p,q);
     return !left ? right : !right ? left : root;
     }
  }
};
*/