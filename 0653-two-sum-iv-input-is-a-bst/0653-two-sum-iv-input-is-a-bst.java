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

/**

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
} */