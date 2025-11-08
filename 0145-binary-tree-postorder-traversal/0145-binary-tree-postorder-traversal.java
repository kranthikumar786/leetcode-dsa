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
    public List<Integer> postorderTraversal(TreeNode root) {
     Stack<TreeNode> st = new Stack<>();
     List<Integer>ans = new ArrayList<>();
      if(root == null)return ans;
      TreeNode cur = root;
      TreeNode lastVistied = null;
       while(cur != null || !st.isEmpty()){
               while(cur != null){
                    st.push(cur);
                    cur = cur.left;
               } 
               cur = st.peek();
               if(cur.right == null ||  lastVistied == cur.right){
                   ans.add(cur.val);
                   st.pop();
                lastVistied = cur;
                cur = null;
               } else{cur = cur.right;}  
       }
       return ans;
     /**
        root.left : 
        root.right :
         root.val :

       save root  :
          1
           2
              4


            4
            2 :  once popped measn check only rihg tside vlues:
                  
            1 


      */

    }
}