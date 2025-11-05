class Solution {
    // void inorder(TreeNode root, List<Integer> arr) {
    //     if (root == null) return;
    //     inorder(root.left, arr);
    //     arr.add(root.val);
    //     inorder(root.right, arr);
    // }
    // TreeNode newroot(List<Integer> arr, int s, int e) {
    //     if (s > e) return null;
    //     int m = (s + e) / 2;
    //     TreeNode root = new TreeNode(arr.get(m));
    //     root.left = newroot(arr, s, m - 1);
    //     root.right = newroot(arr, m + 1, e);
    //     return root;
    // }
    public TreeNode deleteNode(TreeNode root, int key) {
           if(root == null){return root;}
           if(root.val < key){
             root.right = deleteNode(root.right,key);
           } else if(root.val > key){
                root.left =  deleteNode(root.left,key);
           } else{
            if(root.left == null) return root.right;
                else if(root.right == null) return root.left;
                TreeNode successor = findMin(root.right);
                root.val = successor.val;
                root.right = deleteNode(root.right,successor.val); 
           }   
           return root;  
    }
  private TreeNode findMin(TreeNode root){
        TreeNode node = root;
        while(node.left != null){
            node = node.left;
        }
       return node; 
  }   
}
/**
if (root == null) return null;
        List<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        if (!arr.contains(key)) return root; 
        arr.remove(Integer.valueOf(key));        
        return newroot(arr, 0, arr.size() - 1);
 */
/**
 if( root == null){return root;}
        if(root.val == key){
            if(root.right != null) {
                TreeNode temp = root;
                while(temp.right != null){
                     temp = temp.right;
                }
              root = temp;
            } else{
                 if(root.left != null) {
                     TreeNode temp = root.left;
                      while(temp.right != null){
                           temp = temp.right;
                      }
                    root = temp;  
                 }
            }
  
     if(root.val < key){
        return deleteNode(root.right,key);
     }
       return deleteNode(root.left,key);    
        }
 */