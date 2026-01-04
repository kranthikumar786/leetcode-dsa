class Solution {
    public int sumFourDivisors(int[] nums) {
    int totalSum = 0 ;
    for(int num : nums){
          int divisorSum = 0 ;
          int divisiorCount = 0;
          for(int i = 1 ; i*i <= num ; i++) {
               if(num%i != 0 ){
                  continue;
               }
               divisiorCount++;
               divisorSum+=i;
               int divisorPair = num/i;
               if(i != divisorPair){
                   divisiorCount++;
                    divisorSum +=divisorPair;  
               }
                if(divisiorCount > 4){break;}
          }
          if(divisiorCount == 4){
            totalSum += divisorSum;
          }
    }
    return totalSum;
    }
}
/**
TC : O(N* Square(MaxNumberinNums))
SC: O(1)
 */
/**
    int sum = 0 ; 
    for(int num : nums){
        ArrayList<Integer>arr = new ArrayList<>();
          boolean f = false;
        for(int i = 1 ; i <= num; i++) {
               if(num%i == 0){
                 arr.add(i);
               }
                if(arr.size() > 4) {
                      f = true;
                       break;
                }
        }
        if(arr.size() == 4 && !f){
            //sum += arr.stream().sum();
        sum += arr.stream().mapToInt(Integer::intValue).sum();
        System.out.println(num +":::: "+ sum);
        }
    }
    return sum;

 */