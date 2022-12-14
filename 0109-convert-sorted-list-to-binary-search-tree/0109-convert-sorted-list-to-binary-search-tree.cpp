/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
   /* vector<int>a;
    void dfs(ListNode* head) {
        while ( head) {
            a.push_back(head->val);
             head = head->next;
        }
    }
    TreeNode* T (vector<int>a , int l,int h) {
        
         if ( l > h) {
              return NULL;
         }
        if ( l== h) {
             return new TreeNode(a[l]);
        }
        int  m = (l + h)>>1;
        TreeNode* node = new TreeNode(a[m]);
        node->left = T(a,l,m-1);
        node->right = T(a,m+1, h);
        return node;
    }*/
    
    TreeNode * fn(ListNode * head ) {
            if ( !head ) {
                 return NULL;
            }
            if ( !head->next ) {
                 return new TreeNode(head->val);
            }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
         while ( fast && fast->next ) {
             prev = slow;
             slow = slow->next;
             fast = fast->next->next;
             }
         prev->next = NULL;
        TreeNode* node = new TreeNode(slow->val);
        node->left = fn(head);
        node->right = fn(slow->next);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
         /* dfs(head);
         return T(a,0,a.size()-1);
         */
        
        return fn( head );
   }
};