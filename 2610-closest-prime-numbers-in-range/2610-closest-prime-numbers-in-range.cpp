class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> primes(right + 1, true);
        primes[0] = primes[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= right; j += i) {
                    primes[j] = false;
                }
            }
        }

        vector<int> allPrimes;
        for (int i = max(2, left); i <= right; i++) {
            if (primes[i]) {
                allPrimes.push_back(i);
            }
        }

        if (allPrimes.size() < 2) {
            return {-1, -1};
        }

        int min_gap = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 1; i < allPrimes.size(); i++) {
            int gap = allPrimes[i] - allPrimes[i - 1];
            if (gap < min_gap) {
                min_gap = gap;
                result = {allPrimes[i - 1], allPrimes[i]};
            }
        }

        return result;
     
        /*
        1 and  same number are divisors: 
        then it's prime number : 
        
        num1 : , size()!= 1 : so we got 2 : 
        do num1 - num2 :  get min : 
          and update the value of min  :
           track of it : 
        */
    }
};