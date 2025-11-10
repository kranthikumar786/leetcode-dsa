/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    StringBuilder str = new StringBuilder();
    int index  = -1;
       public void C(TreeNode root) {
             if(root == null){
                str.append("# ");
                 return ;
             }
            C(root.left);
            C(root.right); 
       str.append(root.val +" ");
       }
    public String serialize(TreeNode root) {
        C(root);
      return str.toString();
     }
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
      String nodes[] = data.split(" ");
      index = nodes.length;
      return BuildTree(nodes);       
    }
    public TreeNode BuildTree(String[] data){
        index--;
         if(data[index].equals("#")) {
               return null;
         }
        TreeNode root = new TreeNode(Integer.parseInt(data[index]));
         root.right = BuildTree(data);
         root.left = BuildTree(data);
       return root;   
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
/**

pre-Order : 
StringBuilder str = new StringBuilder();
    int index  = -1;
       public void C(TreeNode root) {
             if(root == null){
                str.append("# ");
                 return ;
             }
            str.append(root.val +" ");
            C(root.left);
            C(root.right); 
       }
    public String serialize(TreeNode root) {
        C(root);
      return str.toString();
     }
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
      String nodes[] = data.split(" ");
      return BuildTree(nodes);       
    }
    public TreeNode BuildTree(String[] data){
        index++;
         if(data[index].equals("#")) {
               return null;
         }
        TreeNode root = new TreeNode(Integer.parseInt(data[index]));
         root.left = BuildTree(data);
         root.right = BuildTree(data);
       return root;   
    }

----------------------------------------------------------
public class Codec {

    public String serialize(TreeNode root) {
       if(root == null) return "";
       StringBuilder str = new StringBuilder();
       Queue<TreeNode> q = new LinkedList<>();
       q.offer(root);
         while(!q.isEmpty()){
            TreeNode cur = q.poll();
             if(cur == null) {
                  str.append("n ");
                   continue;
             }
             str.append(cur.val + " ");
             q.offer(cur.left);
             q.offer(cur.right);
         }
     return str.toString();
    }

    public TreeNode deserialize(String data) {
       if(data == "") return null;
        Queue<TreeNode>q = new LinkedList<>();
        String value[] = data.split(" ");
            TreeNode root = new TreeNode(Integer.parseInt(value[0])); 
            q.offer(root);
         for(int i = 1 ; i < value.length ;i++) {
               TreeNode parent = q.poll();
                if(!value[i].equals("n")){
                     TreeNode left = new TreeNode(Integer.parseInt(value[i]));
                     parent.left = left;
                    q.offer(left);
                }
                if(!value[++i].equals("n")){
                    TreeNode right = new TreeNode(Integer.parseInt(value[i]));
                    parent.right = right;
                    q.offer(right);
                }
         }
         return root;
    }
}
 */