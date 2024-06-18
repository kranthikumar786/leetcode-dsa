class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       vector<pair<int,int>>p;
        for(int i=0;i<profit.size();i++){
            p.push_back({profit[i],difficulty[i]});
        }
        int prof=0;
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        for(int j=0;j<worker.size();j++){
            int k=worker[j];
            for(int i=0;i<p.size();i++){
                int x=p[i].first;
                int t=p[i].second;
                if(t<=k){
                prof=prof+x;
                break;
                }
            }
        }
 return prof;
    }
};