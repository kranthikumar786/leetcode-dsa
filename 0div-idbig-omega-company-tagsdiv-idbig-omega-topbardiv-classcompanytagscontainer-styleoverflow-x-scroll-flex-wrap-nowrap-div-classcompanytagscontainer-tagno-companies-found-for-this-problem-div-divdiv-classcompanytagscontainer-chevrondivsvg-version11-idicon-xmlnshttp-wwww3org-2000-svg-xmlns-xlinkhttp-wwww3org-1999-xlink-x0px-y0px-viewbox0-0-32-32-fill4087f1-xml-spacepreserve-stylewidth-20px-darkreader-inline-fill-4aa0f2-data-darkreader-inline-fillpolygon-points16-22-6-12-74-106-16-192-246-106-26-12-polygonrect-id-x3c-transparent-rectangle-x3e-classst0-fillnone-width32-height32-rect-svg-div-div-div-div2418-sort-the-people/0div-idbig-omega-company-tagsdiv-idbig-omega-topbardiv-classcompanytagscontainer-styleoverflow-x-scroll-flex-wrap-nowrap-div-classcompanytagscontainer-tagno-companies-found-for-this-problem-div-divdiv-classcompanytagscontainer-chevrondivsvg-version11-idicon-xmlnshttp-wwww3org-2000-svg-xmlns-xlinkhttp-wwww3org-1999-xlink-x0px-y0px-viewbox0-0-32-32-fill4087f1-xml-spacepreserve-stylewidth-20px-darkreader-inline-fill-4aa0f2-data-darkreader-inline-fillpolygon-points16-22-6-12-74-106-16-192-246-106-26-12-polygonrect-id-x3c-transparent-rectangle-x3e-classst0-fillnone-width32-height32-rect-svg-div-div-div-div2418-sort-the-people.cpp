class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
             vector<pair<int,string>>vec;

             for(int i=0;i<names.size();i++){
                 vec.push_back({heights[i],names[i]});
             }

             sort(vec.begin(),vec.end());

             int n=names.size();

             for(int i=n-1;i>=0;i--){
                 names[n-1-i]=vec[i].second;
             }

         return names;

    }
};
 