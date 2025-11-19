class Solution {
    int hist(int[]prefix){
        int  n = prefix.length;
        Stack<Integer>st = new Stack<>();
        int rect = 0;
        for(int i = 0 ; i <= n ;i++){
            int curH = i == n ? 0: prefix[i];
            while(!st.isEmpty() && prefix[st.peek()] > curH){
                    int height = prefix[st.pop()];
                    int right = i;
                    int left = st.isEmpty() ? 0 : st.peek()+1;
                 rect = Math.max(rect,height*(right-left));   
            }
           st.push(i); 
        }
       return rect; 
    }
    public int maximalRectangle(char[][] matrix) {
       int ans = 0 ;
       int n = matrix.length;
       int m = matrix[0].length;
       int prefix[] = new int[m];      
    for(int i = 0 ; i < n ;i++) {
           for(int j = 0 ; j < m ;j++) {
                 if(matrix[i][j] == '1'){
                    prefix[j] +=1;
                 }else{
                    prefix[j] = 0;
                 }
           }
         ans = Math.max(ans,hist(prefix));  
    }
       return ans;
    }
}

/**

 */