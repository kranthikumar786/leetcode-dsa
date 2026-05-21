class Solution {
    public String largestNumber(int[] nums) {
       int n = nums.length;
       String array [] = new String[n];
       for(int i = 0 ; i < n ;i++) {
         array[i] = String.valueOf(nums[i]);
       } 
       Arrays.sort(array,(a,b)->{
         String o1 = a+b;
         String o2 = b+a;
     return o2.compareTo(o1);
       }); 
       if(array[0].equals("0")) return "0";
       StringBuilder ans = new StringBuilder();
      for(String s : array){
        ans.append(s);
      }
      return ans.toString();
    }
}