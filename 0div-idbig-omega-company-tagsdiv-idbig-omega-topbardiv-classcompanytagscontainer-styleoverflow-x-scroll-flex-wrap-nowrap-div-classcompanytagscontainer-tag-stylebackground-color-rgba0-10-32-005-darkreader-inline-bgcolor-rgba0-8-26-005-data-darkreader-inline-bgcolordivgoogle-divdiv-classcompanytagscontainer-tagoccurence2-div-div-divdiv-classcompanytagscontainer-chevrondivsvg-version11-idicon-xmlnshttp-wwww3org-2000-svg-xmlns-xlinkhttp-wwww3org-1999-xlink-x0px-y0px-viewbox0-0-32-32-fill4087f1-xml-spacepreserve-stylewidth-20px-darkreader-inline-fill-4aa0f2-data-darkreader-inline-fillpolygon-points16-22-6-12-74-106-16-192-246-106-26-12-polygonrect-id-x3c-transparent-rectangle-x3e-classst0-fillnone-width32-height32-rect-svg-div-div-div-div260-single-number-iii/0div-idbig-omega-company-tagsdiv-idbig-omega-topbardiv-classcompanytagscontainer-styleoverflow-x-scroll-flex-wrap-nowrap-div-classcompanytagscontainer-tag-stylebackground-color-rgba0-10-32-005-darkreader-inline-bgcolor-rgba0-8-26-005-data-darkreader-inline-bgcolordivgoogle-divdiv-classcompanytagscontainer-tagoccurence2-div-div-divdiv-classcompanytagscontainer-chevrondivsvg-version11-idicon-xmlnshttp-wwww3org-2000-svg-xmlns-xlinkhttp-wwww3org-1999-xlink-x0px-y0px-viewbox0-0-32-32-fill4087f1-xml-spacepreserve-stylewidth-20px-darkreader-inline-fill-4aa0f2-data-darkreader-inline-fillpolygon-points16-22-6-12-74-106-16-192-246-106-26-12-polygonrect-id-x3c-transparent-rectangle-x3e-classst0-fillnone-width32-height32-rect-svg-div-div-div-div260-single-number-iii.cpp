class Solution {
public:
    vector<int> singleNumber(vector<int>& inputArray) {
       long TotalXor = 0;
       for(int num : inputArray){
              TotalXor ^= num;}
         long  diffset = TotalXor &(-TotalXor) ; 
         int num1 = 0 , num2 = 0;
   for(int num : inputArray){
         if( num & diffset ) {
             num1 ^= num;
           } else {num2 ^= num;}
}
return {num1, num2};
    }
};