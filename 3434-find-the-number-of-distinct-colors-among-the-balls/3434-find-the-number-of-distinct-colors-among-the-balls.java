class Solution {

    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        int[] result = new int[n];
        Map<Integer, Integer> colorMap = new HashMap<>();
        Map<Integer, Integer> ballMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
         if (ballMap.containsKey(ball)) {
                int prevColor = ballMap.get(ball);
                colorMap.put(prevColor, colorMap.get(prevColor) - 1);

                if (colorMap.get(prevColor) == 0) {
                    colorMap.remove(prevColor);
                }
            }
            ballMap.put(ball, color);

            colorMap.put(color, colorMap.getOrDefault(color, 0) + 1);

            result[i] = colorMap.size();
        }
        return result;
    }
}



    /**
    
   
      create an array of limit+1 : {0} :  O(n)
   query :   (Q)
     chanhe value in that index : 
       then add colour  in set  after update the colour  : O(1)
          get size of set into ans  for every Query :  O(1)

TC: 
     10^5 =       

SC :    
O(n) : 
     */
        /**
        0 1 2 3 4 
        * 4            = 1 
          4 5          = 2 
          3 5          = 2   
          3 5 4        = 3 :
        After query 0, ball 1 has color 4. 
After query 1, ball 1 has color 4, and ball 2 has color 5.
After query 2, ball 1 has color 3, and ball 2 has color 5.
After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.
         

 After query 0, ball 0 has color 1.
After query 1, ball 0 has color 1, and ball 1 has color 2.
After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.

    0  1  2  3  4
    1              = 1> 
    1  2           = > 2       
    1  2  2          = > 3 , but colours are distnict : so not index based : let keep color based :


  now in need a data strucute which mainintans the key, value where key are uniques and value if exisint gupdate those : 



   or 

    list of list : with index as colour ..? 


         
         */