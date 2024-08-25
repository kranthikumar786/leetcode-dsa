class Solution {
public:
    
    void pos(TreeNode *t,vector<int>&a)
    {
        if(!t) return;
        pos(t->left,a);
        pos(t->right,a);
        a.push_back(t->val);
     return;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>a;
         pos(root,a);
        return a;
    }
};