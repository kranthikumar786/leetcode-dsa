class Solution {
public:
     int mod = 1e9+7;
     long long pow(long long m, long long n) {
        if (n == 0) return 1;
        return (((n % 2) ? m : 1) * pow(m * m % mod, n / 2)) % mod;
    }
    int countWays(vector<vector<int>>& ranges) {
     
     sort(ranges.begin(),ranges.end());
      
        int cnt = 1 ;
        auto r = ranges[0];
        for(int i = 0 ; i < ranges.size(); i++) {
            
            if(r[1] >= ranges[i][0]){ // Overlapping confimred
               r[1] = max(r[1],ranges[i][1]);  // Update the maxEnd point
            }else{
                r = ranges[i], ++cnt;  // Non-overlpapping cnt and update new Intervals for comparision
            }
        }
    return pow(2, cnt);     
    }
};