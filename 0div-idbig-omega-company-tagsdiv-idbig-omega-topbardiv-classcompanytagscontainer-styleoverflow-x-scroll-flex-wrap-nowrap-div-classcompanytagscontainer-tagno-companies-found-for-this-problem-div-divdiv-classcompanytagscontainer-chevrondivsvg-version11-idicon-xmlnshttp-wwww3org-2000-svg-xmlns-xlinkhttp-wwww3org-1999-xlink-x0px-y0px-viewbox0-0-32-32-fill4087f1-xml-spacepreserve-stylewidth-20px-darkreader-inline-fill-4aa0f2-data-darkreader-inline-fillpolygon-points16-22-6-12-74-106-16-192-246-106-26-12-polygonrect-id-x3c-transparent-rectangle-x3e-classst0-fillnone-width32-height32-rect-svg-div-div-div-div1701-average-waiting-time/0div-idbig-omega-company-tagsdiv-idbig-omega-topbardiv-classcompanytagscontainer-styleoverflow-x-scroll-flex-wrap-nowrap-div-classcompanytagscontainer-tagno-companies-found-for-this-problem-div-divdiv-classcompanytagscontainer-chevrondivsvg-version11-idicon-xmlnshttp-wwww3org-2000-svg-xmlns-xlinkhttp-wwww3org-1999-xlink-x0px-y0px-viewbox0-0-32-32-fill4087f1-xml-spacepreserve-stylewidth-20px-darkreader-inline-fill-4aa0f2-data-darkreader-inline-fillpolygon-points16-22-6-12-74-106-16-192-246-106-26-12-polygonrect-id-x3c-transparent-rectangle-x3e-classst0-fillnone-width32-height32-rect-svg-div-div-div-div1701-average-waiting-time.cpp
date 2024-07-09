class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(); 
        double ans = 0;
         int sum = 0;
        for(int i = 0 ; i < n ;i++) {
            int fistValue = customers[i][0];
            int secondValue = customers[i][1];
            if(sum < fistValue ) {
                 sum = fistValue;
            }
          sum += secondValue;
         ans += (sum - fistValue);   
        }
         double k = customers.size(); 
       return   ans/ k;
    }
};