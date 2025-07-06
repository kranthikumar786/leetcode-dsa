class FindSumPairs {
 
//    int[] arr1 ;
//    int[] arr2;
    int n2 ;
 
  HashMap<Integer,Integer>index2ToValue = new HashMap<>();
  HashMap<Integer,Integer>value2ToFrequency = new HashMap<>();
  HashMap<Integer,Integer>value1ToFrequncy = new HashMap<>(); 
    public FindSumPairs(int[] nums1, int[] nums2) {
        n2 = nums2.length;
       for(int num : nums1) {
          int fre = value1ToFrequncy.getOrDefault(num,0);
          value1ToFrequncy.put(num,fre+1);
       }
       for(int i = 0 ; i < n2 ; i++) {
         index2ToValue.put(i,nums2[i]);
         int fre = value2ToFrequency.getOrDefault(nums2[i],0);
         value2ToFrequency.put(nums2[i],fre+1);
       }
    }
    public void add(int index, int val) {
      int oldValue = index2ToValue.get(index);
      int newValue = oldValue + val;  
       value2ToFrequency.put(oldValue,value2ToFrequency.get(oldValue)-1);
          if(value2ToFrequency.get(oldValue) == 0) {
           value2ToFrequency.remove(oldValue);
          }
        value2ToFrequency.put(newValue,value2ToFrequency.getOrDefault(newValue,0)+1);
      index2ToValue.put(index,newValue);
    }
    public int count(int tot) {
         int pairsCnt = 0 ;
        
          for(Map.Entry<Integer,Integer> entry : value1ToFrequncy.entrySet() ) {
              int val1 = entry.getKey();
              int freq1 = entry.getValue();
              int complement = tot - val1;
              int freq2 = value2ToFrequency.getOrDefault(complement,0);
              pairsCnt += (freq1 * freq2);
          }
     return pairsCnt;
    }
/*
FindSumPairs findSumPairs = new FindSumPairs(
     0  1  2  3  4  5 
    [1, 1, 2, 2, 2, 3], 
    1 -> 2 :
    2 -> 3 : 
    3 -> 1 : 
    [1, 4, 5, 2, 5, 4]);
    1 -> 1: 
    2 -> 1 :
    4 -> 2:
    5 -> 2:  


  now index based   :
   we are updating the values so use another hashMap : 
     two hashMaps:
     index -> value    : 
     value -> frquncey :  


  
findSumPairs.count(7);  // 
return 8; 
pairs (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4

(2,2) (2,4) , (3,2) , (3,4) , (4,2) , (4,4) , (5,1) (5,5)


findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 + 4
 

*/

}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */