class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    priority_queue<long long ,vector<long long>,greater<long long>>Q;
    for(int num : nums){
        Q.push(num);
    }
        int count = 0;
    while(Q.size() > 0 && Q.top() < k){
           count++;
         long long firstMin = Q.top(); Q.pop();
         long long secondMin = Q.top(); Q.pop();
         long long  minV = min(firstMin,secondMin)*2;
         long long maxVal = max(firstMin,secondMin);
         long long sum = minV + maxVal;
         Q.push(sum);
    }
    // 1,2,3,10,11:
    // 4 : 3, 10,11 : 
    // 3 ,4 : 
    //   10 ,10, 11 : 

 return count;
   // dry run : 



    }
};


 /*


 tc : 
 [10,10,10,9]
  k = 10 , 
  Ouput : 1 

  sinc ei have to take two elemnts : 
    if one elment  <10 and another 10 > 10 , what is expected out put : 

 it was mentioend by saying  output will be always exinitg : 
  [10,10,10]  
  k = 10 ;  

   output : 0 : 





 */