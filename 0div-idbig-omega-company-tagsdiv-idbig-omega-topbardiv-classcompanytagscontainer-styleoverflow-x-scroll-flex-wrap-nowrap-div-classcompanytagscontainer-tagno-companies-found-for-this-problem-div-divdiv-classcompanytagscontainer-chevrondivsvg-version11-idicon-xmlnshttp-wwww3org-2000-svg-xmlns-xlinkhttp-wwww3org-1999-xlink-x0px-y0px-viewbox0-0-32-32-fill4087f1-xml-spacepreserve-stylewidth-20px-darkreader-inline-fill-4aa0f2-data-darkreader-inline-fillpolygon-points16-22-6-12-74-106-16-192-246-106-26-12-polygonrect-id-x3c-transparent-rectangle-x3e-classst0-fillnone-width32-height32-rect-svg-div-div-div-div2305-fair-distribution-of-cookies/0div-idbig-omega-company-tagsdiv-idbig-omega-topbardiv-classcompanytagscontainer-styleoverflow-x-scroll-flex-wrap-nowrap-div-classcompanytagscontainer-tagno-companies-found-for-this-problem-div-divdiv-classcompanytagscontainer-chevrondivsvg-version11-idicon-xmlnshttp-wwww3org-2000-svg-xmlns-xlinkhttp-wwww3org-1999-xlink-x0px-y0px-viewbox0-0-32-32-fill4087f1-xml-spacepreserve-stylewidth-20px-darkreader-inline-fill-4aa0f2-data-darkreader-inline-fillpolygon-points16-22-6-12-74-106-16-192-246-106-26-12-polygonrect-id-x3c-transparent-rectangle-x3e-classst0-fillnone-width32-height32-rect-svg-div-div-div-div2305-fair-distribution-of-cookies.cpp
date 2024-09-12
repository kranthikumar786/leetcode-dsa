class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int>& c, int k,vector<int>& b, int i){
        if(i == c.size()){
            int mini = INT_MIN;
            for(int i = 0;i<k;i++){
                mini = max(mini,b[i]);
            }

            ans = min(mini,ans);
            return;
        }

        for(int j = 0;j<k;j++){
            b[j] += c[i];
            solve(c,k,b,i+1);
            b[j] -= c[i];
        }
    }

    int distributeCookies(vector<int>& c, int k) {
        vector<int>b(k,0);
        solve(c,k,b,0);
        return ans;
    }
};