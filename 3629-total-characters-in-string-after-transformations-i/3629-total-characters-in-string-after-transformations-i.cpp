class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> freq(26, 0);
        
        for (char ch : s) freq[ch - 'a']++;
        long long len = s.length();
        
        while (t--) {
            long long z_count = freq[25];
            len = (len + z_count) % MOD;
            
            for (int i = 25; i > 0; i--) freq[i] = freq[i-1];
            
            freq[0] = z_count;
            freq[1] = (freq[1] + z_count) % MOD;
        }
        
        return len;
    }
};
