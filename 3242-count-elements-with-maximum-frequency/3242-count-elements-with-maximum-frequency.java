class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer,Integer>freMap = new HashMap<>();
        int maxFrquncey = 0;
        for(int num : nums){
             int  curFre = freMap.getOrDefault(num,0);
             freMap.put(num,curFre+1);
             maxFrquncey = Math.max(maxFrquncey,curFre+1);  
        }
       int TotalSum  = 0 ;
       for(int Value : freMap.values()) {
            if(Value == maxFrquncey) {
                TotalSum += Value; 
            }
       }  
   return TotalSum;
        /**
        
        [1,2,3,4,5] :
         1 1 1 1 1

         [2 2 2 2 2]
            
            5 : 

     [1,2,2,3,1,4] : 
      2  2      1 : 
      maxFre = 2: 
      next time : simply do iterat then sum it 

         */
    }
}