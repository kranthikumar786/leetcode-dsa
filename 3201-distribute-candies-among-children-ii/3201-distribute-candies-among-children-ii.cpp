class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i <= 2 * limit)
                res += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return res;
    }
};


     // let's say it id  number DP ..? 
        /**
          no   DP propoerites found like no of ways we can do one single activity
           like that so defintely not DP
        
      n = 5 , l = 2: 

      fixed number 3: 

      1 1 1 
      1 1 0 :  : zero can be placed t remaing 2 places as well 
        so total 3 ways: 

     1 1 1 : 




        
        */
 