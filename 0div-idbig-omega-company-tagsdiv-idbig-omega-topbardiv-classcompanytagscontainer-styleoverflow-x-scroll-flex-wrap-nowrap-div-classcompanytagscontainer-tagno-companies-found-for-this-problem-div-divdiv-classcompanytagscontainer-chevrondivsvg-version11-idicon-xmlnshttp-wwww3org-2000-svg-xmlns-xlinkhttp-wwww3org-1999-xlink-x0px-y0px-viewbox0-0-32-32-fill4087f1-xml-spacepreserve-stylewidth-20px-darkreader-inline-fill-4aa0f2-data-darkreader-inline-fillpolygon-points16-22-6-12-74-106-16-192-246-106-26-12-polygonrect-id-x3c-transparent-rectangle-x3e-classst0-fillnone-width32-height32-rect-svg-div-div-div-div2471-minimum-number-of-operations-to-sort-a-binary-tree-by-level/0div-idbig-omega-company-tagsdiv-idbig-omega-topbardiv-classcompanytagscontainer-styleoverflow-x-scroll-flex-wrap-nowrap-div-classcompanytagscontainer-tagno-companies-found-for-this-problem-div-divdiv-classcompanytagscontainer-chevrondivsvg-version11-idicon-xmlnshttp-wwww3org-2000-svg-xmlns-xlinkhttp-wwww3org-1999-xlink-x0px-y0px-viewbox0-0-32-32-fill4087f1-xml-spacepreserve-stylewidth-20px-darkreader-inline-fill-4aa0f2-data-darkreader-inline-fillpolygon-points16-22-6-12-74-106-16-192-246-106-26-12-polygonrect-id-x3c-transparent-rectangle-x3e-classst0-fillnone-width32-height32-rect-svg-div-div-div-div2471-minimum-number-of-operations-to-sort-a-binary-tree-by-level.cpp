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
    int minimumOperations(TreeNode* root) {
       queue<TreeNode*>Q;
        Q.push(root);
        int count = 0;
        while(Q.size()){
             int length = Q.size();
            vector<int>ele(length);
             for(int i = 0 ; i < length ; i++){
                TreeNode* root1 = Q.front();
                   Q.pop();
                  ele[i] = root1->val;
                 if(root1->left){
                     Q.push(root1->left);
                 }
                 if(root1->right){
                     Q.push(root1->right);
                 }
             }
             count += noofSwaps(ele);
        }
        return count;
    }   
  int noofSwaps(vector<int>ele){
      int cnt = 0, elesize = ele.size();
      vector<int> idx(elesize);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j){ return ele[i] < ele[j]; });
      for(int i = 0 ; i < elesize ;){
          int pos = idx[i];
           if(ele[pos] == ele[i]){i++;} 
          else{
               
              swap(ele[pos],ele[i]);
              swap(idx[pos],idx[i]);
              cnt++;
          }
          
      }
      return cnt;
  }  
    
    
    
        
        
        
        
        
        
        /*
        
           push into Q then sort the Q at each level , then simply count the incorrect places : 
      
       1
       
      4  3 
      
      
     7 6 8  5 
  
     sort() : min value should be in front : 
     
     5 6 8 7 : 
    
    
     if( diff = 1)
       min value at begin == min 
        else count++;
        minvalue ++;
        
      
     min : 5   max value : 8 :
       
       
     
     
     
     
     
    
     5 6 7 8 :   
     */
        
    
};