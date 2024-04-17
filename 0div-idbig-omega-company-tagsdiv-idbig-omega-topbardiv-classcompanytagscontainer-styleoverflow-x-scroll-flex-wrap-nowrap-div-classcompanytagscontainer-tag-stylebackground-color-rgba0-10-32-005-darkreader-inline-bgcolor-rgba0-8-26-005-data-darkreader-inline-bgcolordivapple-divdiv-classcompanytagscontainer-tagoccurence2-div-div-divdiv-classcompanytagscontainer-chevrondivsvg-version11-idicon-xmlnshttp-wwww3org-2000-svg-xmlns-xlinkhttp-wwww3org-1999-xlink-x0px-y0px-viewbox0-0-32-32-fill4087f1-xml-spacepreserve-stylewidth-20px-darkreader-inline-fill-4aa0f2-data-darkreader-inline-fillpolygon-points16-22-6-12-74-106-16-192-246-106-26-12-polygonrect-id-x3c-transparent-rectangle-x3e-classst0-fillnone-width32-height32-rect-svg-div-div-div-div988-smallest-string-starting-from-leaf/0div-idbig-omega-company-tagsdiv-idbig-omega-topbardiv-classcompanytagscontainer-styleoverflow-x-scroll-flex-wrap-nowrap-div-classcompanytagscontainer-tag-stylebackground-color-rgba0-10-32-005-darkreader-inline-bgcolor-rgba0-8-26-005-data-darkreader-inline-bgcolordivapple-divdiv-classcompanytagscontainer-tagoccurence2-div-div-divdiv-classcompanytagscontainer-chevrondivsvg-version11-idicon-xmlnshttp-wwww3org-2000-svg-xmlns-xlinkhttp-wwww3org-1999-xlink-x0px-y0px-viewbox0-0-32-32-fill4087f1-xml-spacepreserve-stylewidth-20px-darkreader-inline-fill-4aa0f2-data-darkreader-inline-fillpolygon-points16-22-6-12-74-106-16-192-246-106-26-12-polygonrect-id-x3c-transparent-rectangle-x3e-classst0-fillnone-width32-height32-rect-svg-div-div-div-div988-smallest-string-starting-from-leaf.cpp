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
    string lexicographicallySmaller(const string& str1, const string& str2) {
        if (str1.compare(str2) < 0) {
            return str1;
        } else {
            return str2;
        }
    }


    void solve(TreeNode* root, string &ans, string temp){
        temp = char('a'+root->val) +  temp;
        if(root->left==NULL && root->right==NULL){
            if(ans ==""){
                ans = temp;
            }else{
                ans = lexicographicallySmaller(ans,temp);
            }
            return;
        }
        
        
        if(root->left){
            solve(root->left,ans,temp);
        }
        if(root->right){
            solve(root->right,ans,temp);
        }
        
       
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans ="";
        solve(root,ans,"");
        return ans;
    }
};