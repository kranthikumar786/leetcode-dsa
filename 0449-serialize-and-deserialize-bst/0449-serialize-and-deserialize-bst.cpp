/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
string serialize(TreeNode* root)  {
    string str = "";
    preOrder(root,str);
    return str;          
}
void preOrder(TreeNode* root,string &str) {
	if ( !root ) {
		return;
    }
    str.append(to_string(root->val));
    str.push_back('-');
	preOrder(root->left,str);
	preOrder(root->right,str);
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string str)  {
	TreeNode* root = NULL;
    string s = "";
    for(int i=0;str[i];i++) {
    	if ( str[i] == '-' ) {
    		int num = stoi(s);
    		root = formingBST(root,num);
    		s.clear();
    		continue;
		} else {
		   s.push_back(str[i]);	
		}
	}
	return root;
}
TreeNode* formingBST(TreeNode* root,int &num) {
	if ( !root ) {
		return new TreeNode(num);
	}
	if ( num > root->val) {
		root->right = formingBST(root->right,num);
	}
	if(num < root->val) {
		root->left = formingBST(root->left,num);
	}
	return root;
}
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;