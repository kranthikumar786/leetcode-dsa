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
class Solution {
public:
	void insert(ListNode** root, int item)
	{
		ListNode* temp = new ListNode;
		temp->val= item;
		temp->next = *root;
		*root = temp;
	}
	ListNode* removeNodes(ListNode* head) {
		ListNode* rt=head;
		stack<int>s;
		while(rt){
			if(s.empty()){
				s.push(rt->val);
			}
			else{
				if(!s.empty() && s.top()<rt->val){
					while(!s.empty() && s.top()<rt->val){
						s.pop();
					}
				}
				s.push(rt->val);
			}
			rt=rt->next;
		}
		ListNode *root = NULL;
		while(!s.empty()){
			insert(&root, s.top());
			s.pop();
		}


		return root;
	}
};