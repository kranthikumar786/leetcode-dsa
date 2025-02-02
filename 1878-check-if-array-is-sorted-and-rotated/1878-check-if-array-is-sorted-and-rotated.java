class Solution {
    public boolean check(int[] nums) {
     int n = nums.length;
    if(n <= 1) {return true;}
    int inversions = 0;
    for(int i = 1; i < n ;i++) {
        if(nums[i] < nums[i-1]){
           inversions++; 
           if(inversions > 1){
            return false;
           }
        }
    }
     if(nums[0] < nums[n-1]){
        inversions++;
     }
     return inversions <= 1;


    //  int sortednums[] = new int[n];
    //  int x = -1,minValue = 101;
    //  for(int i = 0; i < n ;i++){
    //       if(minValue > nums[i]){
    //         minValue = nums[i];
    //         x = i;
    //       }
    //  }
    //  for(int i = 0 ; i < n ;i++) {
    //     sortednums[i] = nums[(i+x)%n];
    //  }
    // for(int i = 0 ; i < n-1 ;i++){
    //     if(sortednums[i] > sortednums[i+1]){
    //         return false;
    //     }
    // }
    //  return true;
       /**

6,10,6
6.10.6: 


[3,4,5,1,1,2]
[3,4,5,1,1,2,6]

         first fine min value : 
          then check diff b/w adjacents : 
           if adjeacne diff is differ then check sedonc value is == first value then fine else return false:
            ex : 
              min = 1 
             [3,4,5,1,2] :

             3-4 = 1 : 
             4 - 5 = 1 : 
             5-1 = != 1 
             now check min == 1
              then fine 

              1-2 = 1 : 

              --------------

               duplicates : 
               [3,4,5,1,1,2,6] :
                3<= 4 
                4 <=5 
                5 <=1 
                min ==1 
                1 <= 1 
                1<=1
                2<=6 true but not in sorted order : 

                find min value index 
                 then check it neightbour should be greather then then retuen true else false 
                 : 
                   right side max or equal 
                   lesft side  :  also max , but in test 2 fails : 

                 1  
        A[i] == B[(i+x) % A.length],
        find min value place : 

        Nums[i] = B[(i+x)%N]:

       1 
        nums[0] = B[0+1]%4 : 
        nums[0] = B[1] :  // 1 

        nums[1] = B[1+1] = > B[2] = > 3 : 
        nums[2] = B[2+1] = > b[3] = > 4  : 
        NUMS[3] = b[3+1%4] =  >B[0] = > 2 : 

        1 3 4 2 : 
        now check right adjacen tvalues  and get ans : 
  Tc  :O(N) +o(N):
  Sc:o(N) :
        */ 
    }
}