/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    TreeNode leftCurRoot;
    TreeNode rightCurRoot;

    public TreeNode getNext() {
        TreeNode cur = leftCurRoot;
        while (cur != null) {
            if (cur.left == null) {
                leftCurRoot = cur.right;
                return cur;
            } else {
                TreeNode pre = cur.left;
                while (pre.right != null && pre.right != cur) {
                    pre = pre.right;
                }
                if (pre.right == null) {
                    pre.right = cur;
                    cur = cur.left;
                } else {
                    pre.right = null;
                    leftCurRoot = cur.right;
                    return cur;
                }
            }
        }
        return null;
    }

    public TreeNode getNextReverse() {
        TreeNode cur = rightCurRoot;
        while (cur != null) {
            if (cur.right == null) {
                rightCurRoot = cur.left;
                return cur;
            } else {
                TreeNode succ = cur.right;
                while (succ.left != null && succ.left != cur) {
                    succ = succ.left;
                }
                if (succ.left == null) {
                    succ.left = cur;
                    cur = cur.right;
                } else {
                    succ.left = null;
                    rightCurRoot = cur.left;
                    return cur;
                }
            }
        }
        return null;
    }

    public boolean findTarget(TreeNode root, int k) {
        leftCurRoot = clonedTree(root);
        rightCurRoot = clonedTree(root);
        TreeNode left = getNext();
        TreeNode right = getNextReverse();

        while (left != null && right != null && left.val < right.val) {
            int sum = left.val + right.val;
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left = getNext();
            } else {
                right = getNextReverse();
            }
        }
        return false;
    }
    private TreeNode clonedTree(TreeNode root){
          if(root == null) return null;
          TreeNode node = new TreeNode(root.val);
          node.left = clonedTree(root.left);
          node.right = clonedTree(root.right);
          return node;
    }
}


/**

class Solution {
     TreeNode leftCurRoot ;
     TreeNode rightCurRoot ;
     public TreeNode getNext(){
        TreeNode cur = leftCurRoot;
         while(cur != null) {
            if(cur.left == null) {
                leftCurRoot = cur.right;
                 return cur;  
            } else{
                TreeNode pre = cur.left;
                 while(pre.right != null && pre.right != cur){
                      pre = pre.right;
                 }
                  if(pre.right == null) {
                      pre.right = cur;
                      cur = cur.left;
                  } else{
                     pre.right = null;
                     leftCurRoot = cur.right;
                       return cur;
                  }
            }
         }
         return null;
     }
     public TreeNode getNextReverse(){
        TreeNode cur = rightCurRoot;
          while(cur != null) {
               if(cur.right == null) {
                   rightCurRoot = cur.left;
                   return cur; 
               } else{
                   TreeNode succ = cur.right;
                     while(succ.left != null && succ.left != cur){
                            succ = succ.left;
                     }
                      if(succ.left == null) {
                           succ.left = cur;
                           cur = cur.right; 
                      } else{
                            succ.left = null;
                            rightCurRoot = cur.left;
                            return cur;
                      }
               }
          }
         return null; 
     }
    public boolean findTarget(TreeNode root, int k) {    
       leftCurRoot = root;
       rightCurRoot = root;
       TreeNode left , right ;
       left  = getNext();
       right = getNextReverse();
       while(left != right){
         if(left.val + right.val == k){
             return true;
         } else if(left.val + right.val < k){
               right = getNextReverse();
         } else{
               left  = getNext();
         }
       }
       return false; 
    }
}


 

==========Reverse Inorder Traversal =============
Iterative: 
TreeNode cur = root;
Stack<TreeNode> st = new Stack<>();
List<Integer> ans = new ArrayList<>();

while (cur != null || !st.isEmpty()) {
    while (cur != null) {
        st.push(cur);
        cur = cur.right;   
    }
    cur = st.pop();
    ans.add(cur.val);       
    cur = cur.left;         
}
Morrise Inorder Reversal traversal  : 
List<Integer> ans = new ArrayList<>();
TreeNode cur = root;

while (cur != null) {
    if (cur.right == null) {
        ans.add(cur.val);
        cur = cur.left;
    } else {
        TreeNode succ = cur.right;
        while (succ.left != null && succ.left != cur) {
            succ = succ.left;
        }

        if (succ.left == null) {
            succ.left = cur;
            cur = cur.right;
        } else {
            succ.left = null;
            ans.add(cur.val);
            cur = cur.left;
        }
    }
}
---------------------------------------------------------------------------------
Stack<TreeNode > st = new Stack<>();
        while(cur != null || !st.isEmpty()){
               while(cur != null) {
                   st.push(cur);
                    cur = cur.left;
               }
               cur = st.pop();
              if(ele.contains(k-cur.val)) return true;
              ele.add(cur.val);
               cur = cur.right;   
        }


if(root == null) return false;
      if(ele.contains(k-root.val)) return true;
       ele.add(root.val);
      return findTarget(root.left,k) || findTarget(root.right,k);  

/**
class Solution {
    List<Integer>in1 = new ArrayList<>();
    void in(TreeNode root, int k){
         if(root == null) {return;}
         in(root.left,k);
         in1.add(root.val);
         in(root.right,k);
    }
    public boolean findTarget(TreeNode root, int k) {
      in(root,k);
      int left = 0 , right = in1.size()-1;
       while(left < right){
         int leftS = in1.get(left);
         int rightS = in1.get(right);
         if(leftS + rightS  == k){ return true;}
         else if(leftS + rightS > k) {
              right--;  
         } else{
            left++;
         }
       }    
      return false; 
    }
}

---------------------------------------------------------------


class Solution {
   HashSet<Integer>ele =new HashSet<>();
    public boolean findTarget(TreeNode root, int k) {    
       TreeNode cur = root;
        while(cur != null){
             if(cur.left == null) {
                    if(ele.contains(k-cur.val)) return true;
                    ele.add(cur.val);
                   cur = cur.right; 
             } else{
                  TreeNode pre = cur.left;
                  while(pre.right != null && pre.right != cur){
                          pre = pre.right;
                  }
                   if(pre.right == null){
                       pre.right = cur;
                       cur = cur.left;
                   } else{
                       pre.right = null;
                       if(ele.contains(k-cur.val)) return true;
                       ele.add(cur.val);
                   cur = cur.right;
                   }
             }
        }
        return false; 
    }
}


 */