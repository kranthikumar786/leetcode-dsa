class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(),points.end());
      vector<vector<int>>ans;
        int n = points.size();
        for(int i = 0 ;i < n ; i++) {
            if(!ans.empty() && ans.back()[1] >= points[i][0]){
                  ans.back()[0] = max(ans.back()[0],points[i][0]);
                  ans.back()[1] = min(ans.back()[1], points[i][1]);    
            } else {
                ans.push_back(points[i]);
            }
        }
        return ans.size();
    }
};