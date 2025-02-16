class Solution {
    public int[] constructDistancedSequence(int n) {
        int len = 2 * n - 1;
        int[] result = new int[len];
        boolean[] used = new boolean[n + 1];
       backtrack(result, used, 0, n);
        return result;
    }
    private boolean backtrack(int[] result, boolean[] used, int index, int n) {
        while (index < result.length && result[index] != 0) 
            index++;

        if (index == result.length) 
            return true;

        for (int num = n; num >= 1; num--) {
            if (used[num]) continue; 
            
            int secondPos = (num > 1) ? index + num : index;
            if (secondPos < result.length && result[secondPos] == 0) {
                result[index] = num;
                if (num > 1) result[secondPos] = num;
                used[num] = true;

                if (backtrack(result, used, index + 1, n))
                    return true;

                result[index] = 0;
                if (num > 1) result[secondPos] = 0;
                used[num] = false;
            }
        }
        return false; 
    }}

     /**
      n = 3 : 
      [3,1,2,3,2] 
      length = out of : 
    [3,1,2,3,2]
     0 1 2 3 4 
  
     [2,3,2,1,3] : 
   
     

      start thinking of : 
       3 , 1 ,2 ,3,2
    n = 4 : 
     4, 3, 1, 2, 3 ,2 , 4,
     0  1  2  3  4  5   6 
  deque won't work .. like adding the value from front and back : 
       llet's think of indexes and large value and small value : 
        [3,1, 2 ,3,2,4] which is kind of leanding incrrecotr : 
          becuase :
         first number should start with
          n only : 
          then reduce one by one : 
          5 ,4 , 3 , 2, 1 , 1, 2, 3 ,4,5 : 
          recuesion is awhat aim able to think : 
         becuase of i can see have to genrate good noof possbilities :

         take and don't take : 
         onservation is : always start with 5 : 
           
            end with  2 : 
      
       lenght of it : n * 2+1 : 
                     4*2 + 1 = 9  elemnts :
      
           position : 

              arr[0] = n : 
              arr[end-1] = 2 ;
              arr[end-3] = 2 : 

    arr[] = {5,0,0,0,0,5,2,0,2} :
            
            5 & 2 were done : 
            1 , 4,  ,
             now 3 also done : 
            1,4 : 
            1 i can keep anu wher :
             4
          = {5,3,0,0,3,5,2,0,2} : 
             
              check the length  
               {5,3,1,4,3,5,2,4,2} : 

            check the postion : with odd lenght as well : 
              since 5 is odd then next ele should 3 :  

             fille the lenght arr[0+n] = 5 : 
 --------------------------
  even : n = 2 : 

      3 = [2,1,2] : 
      4 = [4,0,0,0,0,0,0] : 
           0 1 2 3 4 5 6 


          = [4,0,0,0,4,0,0] : 
           = [4,2,0,2,4,0,0]

             [4,2,3,2,4,3,1] :
             arr[0] = n : 
                          arr[n-1] = 2 if n %2 == 1 
                          arr[n-1] = 1 if n %2 == 0
                          arr[1] == n-1 if n%2 == 0
                          arr[1] == n-2 if n%2 == 1 : 

           = 


      bigger number and smaller number should be at one place in middle : 
      
        bigger number and close bigger number should be at beginging 
          smaller  number and very smaller  number should at end : 



      7 :
     6*2 +1 : 13 :  
        0 1 2 3 4 5 6 7 8 9 10 11 12 13
       [0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0] : 
       [7,0,0,0,0,0,0,7,0,0,0, 0, 0, 0] : 

      */   
 