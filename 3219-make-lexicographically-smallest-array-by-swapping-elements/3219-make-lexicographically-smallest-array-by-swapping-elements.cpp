class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& v, int lim) {
        int n=v.size();
        vector<pair<int,int>>vp; 
        for(int i=0;i<n;++i)vp.push_back({v[i],i});
        sort(vp.begin(),vp.end());
        vp.push_back({vp[n-1].first+lim+1,0});
        vector<int>ans(n);
        vector<int>idx,val;
        for(int i=0;i<n;++i){
            if(vp[i+1].first-vp[i].first<=lim){
                idx.push_back(vp[i].second); 
                val.push_back(vp[i].first);
            }
            else{
                idx.push_back(vp[i].second); 
                val.push_back(vp[i].first);
                sort(idx.begin(),idx.end()); 
                sort(val.begin(),val.end()); 
                for(int j=0;j<idx.size();++j)ans[idx[j]]=val[j];
                idx.clear(); 
                val.clear();
            }
        }
        return ans;
    }
};