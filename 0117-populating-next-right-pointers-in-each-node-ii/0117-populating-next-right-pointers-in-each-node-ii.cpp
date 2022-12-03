/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
         if ( !root ){
               return root;
         }
        
    /*
        queue<Node*> q;
         q.push(root);
         q.push(NULL);
        while ( q.size() > 1 ) {
             Node* curr = q.front();
             q.pop();
             if ( !curr ){
                q.push(NULL);
                continue;
             }
            curr->next = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return root;
    }
};
approachBFS = {
     TimeComplexity = O(n),
     SpaceComplexity = O(pow(2,h)-1) for Perfect Binary Tree
}

*/
/*
        Node* head = NULL; //head of the next level
        Node* prev = NULL; //the leading node on the next level
        Node* cur = root;  //current node of current level
        while ( cur ) {
            while (cur ) { //iterate on the current level
                if ( cur->left ) {
                    if (prev) {
                        prev->next = cur->left;
                     } else {
                        head = cur->left;
                    }
                    prev = cur->left;
                }
                if ( cur->right ) {
                    if ( prev ) {
                        prev->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    prev = cur->right;
                }
                //move to next node
                cur = cur->next;
            }
            //move to next level
            cur = head;
            head = NULL;
            prev = NULL;
        }
    
    return root ;
    }
};  
approachHeadPrev = {
    TimeComplexity = O(n),
    SpaceComplexity =O(1)
};
*/

  if ( !root ) {
        return root;
  }
        Node* cur = root;
        Node* Head = new Node(0);
        Node* prev = Head;
        while ( cur ) {
            if ( cur->left ) {
                prev->next = cur->left;
                prev = prev->next;
            }
            if ( cur->right ) {
                prev->next = cur->right;
                prev = prev->next;
            }
            if (cur->next ) {
                cur = cur->next;
            }
            else {
                cur = Head->next;
                Head->next = NULL;
                prev = Head;
            }
        }

return root;
}
};



















