class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    
        if( n ==0 ) return 1;
        vector<int>res(n+1);
        res[0] =9;
        int sum = res[0];
        for (int i = 0; i < n-1; i++) {
            res[i+1] = res[i]*(9-i);
            sum += res[i+1];
        }
        
        return sum+1;
        
    }
};