class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans=0;
        vector<vector<int>>mincost(26,vector<int>(26,1e9));
        for(int i=0;i<26;i++){
            mincost[i][i]=0;
        }
        for(int i=0;i<cost.size();i++){
            mincost[original[i]-'a'][changed[i]-'a']=min(cost[i],mincost[original[i]-'a'][changed[i]-'a']);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (mincost[i][k] != INT_MAX && mincost[k][j] != INT_MAX && mincost[i][k] + mincost[k][j] < mincost[i][j]) {
                        mincost[i][j] = mincost[i][k] + mincost[k][j];
                    }
                }
            }
        }
        for(int i=0;i<target.size();i++){
            if(mincost[source[i]-'a'][target[i]-'a']>=1e9){
                return -1;
            }else{
                ans+=mincost[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};