class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
     
      int res = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];

        unordered_map<int, int> counter;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter = {{0,1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};

/*
        
        is Always Target Found ..? or atLeastOnce..?
        
        Approahc : 
            travese the given matrix with 4 sides . 
              mean while travesing sum in that paritcualr path . and if sum == target then cnt++
              
               target = 0 ; 
                 
                [0, 1,-1,0,0] = >  1 , 2, 3, 4 1 st row : 
                [-1,-1,-1,-1,0]; = > 1 :  row wise 
                
                  Since we cna trvese 4 ways : 
                   1+ (-1) = 0 : shoudl we conside this ans well ..? 
                   yes , cnt++;
                
          x-1 , y
 x,y-1    [x,y] = >  x, y+1  
             
            x+1 , y
            
            
            Square Matrxi given 
            
          followup : 
          
          single elemnt ..? 
          
           above test case special case is zero : becuase of addtion [sum] : 
           targe = > which may lead to inteer overflow..
          ans : ans can fit in integer or do we have to include % then return ans ..? 
             
          
          best case Time compleixty : 
             single elemtns  : 
          Avg case and worst case since we have to travese the entire Matrix:
 
      Target = 0 
        [ 0 ,0 ,0 ,0 ,0 ,0 ]
        [ 0 ,0 ,0 ,0 ,0 ,0 ]
        [ 0 ,0 ,0 ,0 ,0 ,0 ]
        [ 0 ,0 ,0 ,0 ,0 ,0 ]
        [ 0 ,0 ,0 ,0 ,0 ,0 ]
        [ 0 ,0 ,0 ,0 ,0 ,0 ]
             36 is ans ..? or more then that ..? 
    
         only one time should be calcuated ..? then in that secanrion . 
         we will modify the Matrix ..? 
         no  , or else we cna copy and modify ..? 
         
        [-1001] : which not in our range also 
        
         
         target is an integer  so target could be ans whole number + positvr, 0 , -ve values ..
         even in matrx as given is integer so +ve , 0 , -ve as well.
        no chance of sorting 
          but chance of duplicates .. 
         Single number can possible like for instance  all zeros in array . 

        logic : 
        
         travese throught the given Marix = > O(n*n) 
         mean while travesing  the matrix  sum the every submtarx ..and if target == sum ans++ ;
         
    ans also i have to take care about .. only begining should i make as visited or entire path that i have explored make as an visited...? 
          
          since  the way iam explore is know as sub matrix  so i will be mkaing exploreing path as visited if i get sum == target . else let it be 
        */
           