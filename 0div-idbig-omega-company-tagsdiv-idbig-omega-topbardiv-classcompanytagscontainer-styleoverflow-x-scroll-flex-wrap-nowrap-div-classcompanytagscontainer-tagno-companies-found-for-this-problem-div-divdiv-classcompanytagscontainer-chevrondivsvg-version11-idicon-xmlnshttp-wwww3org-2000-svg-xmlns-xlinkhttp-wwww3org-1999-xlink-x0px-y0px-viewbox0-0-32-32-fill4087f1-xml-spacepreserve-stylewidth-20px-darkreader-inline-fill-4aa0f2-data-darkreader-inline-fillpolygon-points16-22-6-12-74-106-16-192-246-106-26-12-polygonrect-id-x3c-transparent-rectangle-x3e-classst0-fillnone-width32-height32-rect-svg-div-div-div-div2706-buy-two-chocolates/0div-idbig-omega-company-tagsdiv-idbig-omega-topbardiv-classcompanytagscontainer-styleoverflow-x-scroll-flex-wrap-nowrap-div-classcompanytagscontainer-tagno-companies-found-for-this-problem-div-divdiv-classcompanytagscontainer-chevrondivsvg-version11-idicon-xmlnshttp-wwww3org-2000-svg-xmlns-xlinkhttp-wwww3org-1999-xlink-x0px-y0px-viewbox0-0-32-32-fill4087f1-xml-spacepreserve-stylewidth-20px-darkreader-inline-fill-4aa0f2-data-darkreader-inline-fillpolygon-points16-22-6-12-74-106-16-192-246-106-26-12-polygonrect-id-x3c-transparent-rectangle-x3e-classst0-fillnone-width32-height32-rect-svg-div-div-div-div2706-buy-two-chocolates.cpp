class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
         int n = prices.size();
        int i = 0;
        int cnt = 0;
        int originalMoney = money; 
        while(money > 0 &&  i < n) {
            
            if(cnt > 2) {
                return originalMoney;
            }
              if(prices[i] <= money) {
                   cnt++;
               cout<<money<<" "<<prices[i]<<"\n";
                  money -= prices[i];
                  if(cnt == 2) {
                      return money;
                  }
              }
            i++;
        }
        
      return originalMoney;  
    }
};