class Solution {
public:
    vector<int> res;
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(auto i : rolls) sum += i;
        sum = mean*(rolls.size() + n) - sum;
        if(sum <= 0) return {};
        if(n * 6 < sum || sum < n) return {};
        int x = sum/n;
        for(int i = 0; i < n; i++) {
            res.push_back(x);
        }
        int re = sum%n;
        int i = 0;
        while(re--){
            res[i] += 1;
            i++;
        }
        return res;
    }
};