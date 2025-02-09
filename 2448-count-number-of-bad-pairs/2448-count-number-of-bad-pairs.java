class Solution {
    public long countBadPairs(int[] nums) {
       int n = nums.length;
       long  badPairCount = 0 ;
       Map<Integer,Integer>map = new HashMap<>();
       for(int i = 0 ; i < n ;i++) {
          int diff  = i- nums[i];
          int goofPairsCount = map.getOrDefault(diff,0);
         badPairCount += i-goofPairsCount;
      map.put(diff,goofPairsCount+1);     
       }
    return badPairCount;
    }
}

/**

//         4 :    4-0   
    //         0:  4 != 0 : cnt = 1; 
    //    3-2: 1:  1 is not present means : all previous value can contribute to your ans : 

             /*for(int j = i +1 ; j < n ;j++) {
                 if((j - i) != (nums[j]- nums[i])) {
                      badPairCount++;
                 }
             }*/

// (j - i) != (nums[j]- nums[i])
// -i+nums[i] = nums[j]-j;
// nums[i]-i = nums[j]-j;

//  push into hash : 
//    hashMap[nums[i] - i]: : 
//   continaSKey should  be false : 
//    then count++;
//  TC : O(N^2) = 10^10 > 10^9 :
//  SC: O(1) : 
//  verdict : TLE 
//  */