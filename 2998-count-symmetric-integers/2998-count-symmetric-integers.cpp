class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans1 = 0 ;
           int digits = to_string(low).length();
            digits *= 10;
          while(low <= high) {
            string s = to_string(low) ;
               if(s.length()%2 == 1){
                 int nextLength = s.length() + 1;
                low = pow(10, nextLength - 1);
                      continue;   
               }else{
                      vector<int>ans;  
                      int num = low;
                        while(num){
                            ans.push_back(num%10);
                            num /= 10;
                        }
                    int leftPtr = 0, rightPtr = ans.size()-1;
                     int leftSum = 0, rightSum = 0;  
                       while(leftPtr < rightPtr) {
                           leftSum += ans[leftPtr++];
                           rightSum += ans[rightPtr--];
                       }  
                       if(leftSum == rightSum) {
                        ans1++;
                       }
               low++;
               }
          }
  return ans1;
    }
};