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
    bool isEvenOddTree(TreeNode* root) {
     /*
       Depth of given binray tree.
       Travesling the tree in BFS trvesal. 
       Best cases are exitign like constrains might fail at  example : 2/10 level .. 
    
    
     */
     
        queue<TreeNode*>q;
        q.push(root);
     
         int lev = 0;
        while (q.size()) {
            int l=q.size();
             int last;
              for(int i=0;i<l;i++)
              {
                  TreeNode* t=q.front();
                  
                  if(lev%2==0&&i>0&&last>=t->val)
                       return 0;
                   if(lev%2!=0&&i>0&&last<=t->val)
                        return 0;
                     
                   if(lev%2==0&&t->val%2==0)
                        return false;
             if(lev%2!=0&&t->val%2!=0)
               return false;
                  last=t->val;
                    q.pop();
                  if(t->left)
                    q.push(t->left);
                  if(t->right)
                     q.push(t->right); 
              }
             ++lev; 
        }
        return true;
    }
};

/*

[1,10,4,3,null,7,9,12,8,6,null,null,2] = pass
with Duplicate + Best case to return false : [1,10,10,3,null,7,9,12,8,6,null,null,2] = pass
base case : [1] = pass
left skewd tree = [1,2,null,3] =pass
right skewed Tree = [1,null,2,null,null,null,3] = > invalid test case 

Question Based Test cases : 
odd level true test case : 
odd level false Test case : 

*/