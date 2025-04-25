class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n = fruits.size();
             int ans = 0;
            for(int i = 0 ; i < n ;i++) {
                  int fruit = fruits[i];
                    bool f = 0;
                for(int j = 0 ;j < n ;j++) {
                     if(baskets[j] != -1 && baskets[j] >= fruit){
                        baskets[j] = -1;
                         f = 1;
                         break;
                     }
                }
                if(!f){ans++;}
            }
            return ans;
    }
};