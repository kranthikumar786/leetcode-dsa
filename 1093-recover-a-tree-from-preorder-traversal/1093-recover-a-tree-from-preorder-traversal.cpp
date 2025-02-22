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
        stack<TreeNode*> st;
        int n = traversal.size();
        
        for (int index = 0; index < n; ) {
            int depth = 0;
            while (index < n && traversal[index] == '-') {
                depth++;
                index++;
            }

            long long value = 0;  
            while (index < n && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index] - '0');  
                index++;
            }

            TreeNode* node = new TreeNode((int)value);  
            while ((int)st.size() > depth) {
                st.pop();
            }

            if (!st.empty()) {
                if (!st.top()->left) st.top()->left = node;
                else st.top()->right = node;
            }

            st.push(node);
        }

        while (st.size() > 1) st.pop();  
        return st.top();
    }
};

   /*
      ROOOT, LEFT ,RIGHT LEVEL BY LEVEL : 
       TAKE ROOT : 
       1 :  EXPLORE IT'S LEFT AND RIGHT :
         1   2 AND 5 IN q:
       1: 
     create new node and that should be left one : 
     1
     / \
     2  5 
    /   /
    3  6 
    /  / 
    4  7 
   
   
    is thier any chance to hvae   like  randome depths in middle ...? 

      "1-2--3---4-5--6---7" : 
       1
       CD = 1 : count = 1: 
       1
       2
       3
       4 
       
        how to get back to it's depth 1 from depth 4 is my doubt is :

   */      
    