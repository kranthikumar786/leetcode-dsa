class Solution {
    public int sumFourDivisors(int[] nums) {
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
    }
}