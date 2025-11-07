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
       if(root == null) return false;
      if(ele.contains(k-root.val)) return true;
       ele.add(root.val);
      return findTarget(root.left,k) || findTarget(root.right,k);  
    }
}

/**

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