class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int c) {
        sort(h.begin(), h.end(), greater<int>());
        int k=0;
        long long ans = 0;
        for(int i : h){
            if (i-k <= 0 || c<=0){
                break;
            }
            ans += i-k;
            c--;
            k++;
        }
        return ans;
    }
};