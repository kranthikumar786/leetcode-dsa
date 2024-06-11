class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto x:arr1){
            mp[x]++;
        }
        int ind = 0;
        for(auto x:arr2){
            while(mp[x]>0){
                arr1[ind++]=x;
                mp[x]--;
            }
        }
        for(auto x:mp){
            while(mp[x.first]>0){
                arr1[ind++]=x.first;
                mp[x.first]--;
            }
        }
        return arr1;
    }
};