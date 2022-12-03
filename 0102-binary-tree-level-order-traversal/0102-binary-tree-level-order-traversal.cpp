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
/*============approach1 ==== PreOrderTraversal ===========Start============
approach1 
       ->  if root is null return;
       ->  if newlevel then create a newVector of vector to store newly created level
       ->  each level conatins vector so store values in it:
       -> move first root->left then root->right
       -> dO Recursively above all step till all nodes complete
class Solution {
public:
    vector<vector<int>>levelOr;
    void PreOrder(TreeNode *root , int level ) { 
            if ( !root ) {
                   return;
            }
            if (levelOr.size() == level ){
                  levelOr.push_back(vector<int>());
            }
            levelOr[level].push_back(root->val);
            PreOrder(root->left,level+1);
            PreOrder(root->right,level+1);
    }    
    vector<vector<int>> levelOrder(TreeNode* root) {
            if ( !root ){
                 return levelOr;
            }
        PreOrder(root,0);
       return levelOr; 
        }
};      
approach1Complexity = {
       TimeComplexity  = O(n),
       SpaceComplexity = O(n) for Skewed Tress
};
============approach1 ==== PreOrderTraversal ===========End============*/
/*============approach2 ==== levelOrderTraversal with Two loops ===========Start============
approach2
  -> if root null return {};
  -> push root into queue for further visiting
  ->get size no of elements that have to visit 
  -> and explore childrens of every node
  ->iteratively do above steps till queue becomes empty.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>levelOr;
            if ( !root ){
                 return levelOr;
            }
         queue<TreeNode*>q;
         q.push(root);
       while ( !q.empty() ) {
           
             int size = q.size();
              vector<int>level;
             for (int i = 0 ; i < size ; i++ ){
                 
                      TreeNode * curNode = q.front();
                      q.pop();
                      level.push_back(curNode->val);    
                    if (curNode->left) {
                         q.push(curNode->left);
                    }
                    if(curNode->right) {
                        q.push(curNode->right);
                    }
             }
           
       levelOr.push_back(level);
       }
        return levelOr;
    }  
};      
/*
approach2Complexity = {
       TimeComplexity = O(n),
       SpaceComplexity =O(pow(2,h)-1) for Perfect Binary Tree
};
*/    



/* ============approach2a ==== levelOrderTraversal with Two loops ===========End============*/
 

/* ============approach2a ==== levelOrderTraversal with Single loop===========Start============
 approach2a
  -> same as approach2 but with single loop
  -> push root and NULL into queue  here NULL represent level end
  -> explore node left childe then right child
  -> if curNode is NULL add level into levelOr then push NULL into queue and Create newVector with empty size
  -> do iteratively above all steps till q.size()>1
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>levelOr;
            if ( !root ){
                 return levelOr;
            }
         queue<TreeNode*>q;
         q.push(root);
         q.push(NULL);
         vector<int>level;
         while ( q.size() > 1) {
               TreeNode* curNode = q.front();
               q.pop();
               if ( curNode ) {
                 level.push_back( curNode->val );   
               if ( curNode ->left ){
                   q.push(curNode->left);
               }
               if (curNode ->right ){
                   q.push(curNode->right);
               }
             } else {
                   levelOr.push_back(level);
                    level = {};
                   q.push(NULL);
               }
          }
        levelOr.push_back(level);
       return levelOr;
    }
};
/*
approach2aComplexity = {
       TimeComplexity =  O(n),
       SpaceComplexity = O(pow(2,h)-1) for Perfect Binary Tree 
};
*/
/* ============approach2a ==== levelOrderTraversal with single loop ===========End============*/
/*
Thank You.
Happy Coding!!!.
return findHelpFul ? pleaseUpVote : pleaseCommentsForImprovemnts;

https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/2874491/C%2B%2B-ororEASY-oror-DFS-oror-BFS-oror-Single-Loop
*/


