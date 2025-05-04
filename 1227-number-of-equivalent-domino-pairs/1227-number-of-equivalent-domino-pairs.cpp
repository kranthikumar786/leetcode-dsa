class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto &x : dominoes) {
            int key = 0;
            key = key | (1 << x[0]);
            key = key | (1 << x[1]);
            if(mp.count(key))
                ans += mp[key];
            mp[key]++;
        }
        return ans;
    }
};