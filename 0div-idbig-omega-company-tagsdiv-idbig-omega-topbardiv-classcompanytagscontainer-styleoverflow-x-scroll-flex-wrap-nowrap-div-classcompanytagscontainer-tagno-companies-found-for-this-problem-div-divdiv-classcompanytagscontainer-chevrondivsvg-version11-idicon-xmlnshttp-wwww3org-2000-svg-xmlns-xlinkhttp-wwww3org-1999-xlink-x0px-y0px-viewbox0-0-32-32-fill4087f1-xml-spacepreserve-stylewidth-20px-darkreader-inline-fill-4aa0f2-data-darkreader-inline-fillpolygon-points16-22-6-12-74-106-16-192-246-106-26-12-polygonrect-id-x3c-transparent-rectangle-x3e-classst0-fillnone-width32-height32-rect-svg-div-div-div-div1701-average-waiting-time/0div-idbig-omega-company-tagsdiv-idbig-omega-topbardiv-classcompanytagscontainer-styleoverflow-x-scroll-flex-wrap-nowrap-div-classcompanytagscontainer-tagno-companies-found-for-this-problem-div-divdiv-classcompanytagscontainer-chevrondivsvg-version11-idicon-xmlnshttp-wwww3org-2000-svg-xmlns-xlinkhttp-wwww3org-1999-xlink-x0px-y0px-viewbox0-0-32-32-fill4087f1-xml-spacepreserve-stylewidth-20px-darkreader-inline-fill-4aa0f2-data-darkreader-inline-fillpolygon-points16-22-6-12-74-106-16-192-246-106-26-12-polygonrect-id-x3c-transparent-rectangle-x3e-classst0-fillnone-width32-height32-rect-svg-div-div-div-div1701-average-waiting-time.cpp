class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
       
      double cur = 0 , waitingTime = 0;
        for(auto customer : customers) {    
            cur = max(cur , 1.0 * customer[0]) + customer[1];
              waitingTime += cur -customer[0]; 
        }
        return  (waitingTime/customers.size());}
};