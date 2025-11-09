/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
         TreeNode cur = root;
         while(cur != null){
             if(cur.val < p.val && cur.val < q.val){
                cur = cur.right;
             } else if(cur.val > p.val && cur.val > q.val){
                 cur = cur.left;
             }else{
             return cur;}
         }
        return root; 
    }
}
/**

class Solution {
    boolean f = 0;
    List<TreeNode>pL = new ArrayList<>();
    List<TreeNode>qL = new ArrayList<>();
    void rec(TreeNode r, int v,boolan p){
         if(r == null) return;
         if(f) return;
         if(p)
            pl.add(v);
         else
           qL.add(v); 
         if(r.val == v){
            return;
         }
         if(r.val > v)
         rec(r.left,v);
         rec(r.right,v); 
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
       rec(root,p,1);
       rec(root,q,0);  
      TreeNode ans = null;
       int i = 0 ;
      while(i < pL.size()  && i < qL.size() && pL.get(i) == qL.get(i)) {
           ans = pL.get(i);
          i++;
      }
      return ans;
    }
}
 */